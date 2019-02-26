'''
#########################################################################
# File : parser.py
# Author: mbinary
# Mail: zhuheqin1@gmail.com
# Blog: https://mbinary.xyz
# Github: https://github.com/mbinary
# Created Time: 2018-09-17  22:19
# Description:
#########################################################################
'''
import argparse
from token_scanner import gen_token

argp = argparse.ArgumentParser()

argp.add_argument('-c','--code',help="output generated code", action='store_true')
args = argp.parse_args()
CODE = args.code

class parser(object):
    def __init__(self):
        self.tokens =None
        self.n = 0
        self.i= 0
    def isType(self,s):
        return self.i<self.n and self.tokens[self.i].type==s
    def isEnd(self):
        return self.i>=self.n
    def match(self,tp=None):
        cur = self.tokens[self.i]
        #print(self.i,tp,cur)
        if tp is None or cur.type==tp:
            self.i+=1
            return cur
        raise Exception('[parse error] Expect {}, got {}'.format(tp,cur.type))
    def parse(self,tokens):
        self.tokens=tokens
        self.i = 0
        self.n = len(self.tokens)
        try:
            self.statement()
            if self.i<self.n:
                print('[parse error] invalid statement')
        except Exception as e:
            print(e)
    def statement(self):
        pass


class declarationParser(parser):
    type_size = {'INT':1,'POINTER':1,'VOID':1}
    def statement(self):
        '''non-terminate-symbol: translation_unit'''
        while self.i<self.n:
            for i in self.declaration():
                print(i)
    def declaration(self):
        symType = self.declaration_specifiers()
        li = self.init_declarator_list(symType)
        self.match('SEMICOLON')
        return li
    def declaration_specifiers(self):
        return self.type_specifier()
    def type_specifier(self):
        return self.match().value
    def init_declarator_list(self,symType):
        li = []
        while 1:
            li.append(self.init_declarator(symType))
            if  self.isType('COMMA'):
                self.match()
            else:break
        return li
    def init_declarator(self,symType):
        return self.declarator(symType)
    def declarator(self,symType):
        np = self.pointer() # np>=0
        tp = 'pointer(' *np + symType + ')'*np
        return self.direct_declarator(tp)
    def direct_declarator(self,tp):
        args =''
        inner = '$'
        name = ''
        if self.isType('NAME'):
            name = self.match().value+'::'
        elif self.isType('LEFT'): # (
            self.match()
            inner = self.declarator('$') #mark
            self.match('RIGHT')
        if self.isType('LEFT'):
            self.match()
            li = ['void']
            if not self.isType('RIGHT'):
                li = self.parameter_type_list()
            self.match('RIGHT')
            if self.isType('L2'):
                raise Exception('[Error]: Array of Functions is not allowed')
            args = ' X '.join(li)
        elif self.isType('L2'):
            li = []
            while self.isType('L2'):
                self.match()
                assert self.isType('NUM')
                li.append(int(self.match().value))
                self.match('R2')
            if self.isType('LEFT'):
                raise Exception('[Error]: Array of Function can not be returned from functions')
            for i in reversed(li):
                tp = 'array({},{})'.format(i,tp)
        if args!='':
            tp = 'function( {args} => {tp})'.format(args=args,tp =tp )
        return name+inner.replace('$',tp)

    def pointer(self):
        n = 0
        while self.isType('POINTER'):
            n+=1
            self.match('POINTER')
        return n
    def parameter_type_list(self):
        return self.parameter_list()
    def parameter_list(self):
        li = []
        while 1:
            argType = self.parameter_declaration()
            li.append(argType)
            if self.isType('COMMA'):
                self.match()
            else:break
        return li
    def parameter_declaration(self):
        symType = self.declaration_specifiers()
        return self.declarator(symType)

def testFromStdIO():
    dp = declarationParser()
    while 1:
        s = input('>> ')
        tk = [i for i in gen_token(s)]
        dp.parse(tk)
def testFromFile(f= 'test.txt'):
    dp = declarationParser()
    with open(f,'r') as fp:
        for line in fp:
            line = line.strip(' \n')
            if line.startswith('//') or line=='' :continue
            print('>>',line)
            tk =[i for i in  gen_token(line)]
            dp.parse(tk)
            print()

if __name__=='__main__':
    testFromFile()
    testFromStdIO()
