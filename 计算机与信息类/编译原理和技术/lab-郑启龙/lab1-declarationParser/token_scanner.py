'''
#########################################################################
# File : token_scanner.py
# Author: mbinary
# Mail: zhuheqin1@gmail.com
# Blog: https://mbinary.xyz
# Github: https://github.com/mbinary
# Created Time: 2018-11-01  12:58
# Description: 
#########################################################################
'''
import re
NAME = r'(?P<NAME>[a-zA-Z_][a-zA-Z_0-9]*)'
NUM = r'(?P<NUM>\d*\.\d+|\d+)' # note that don't use \d+|\d*\.\d+

POINTER = r'(?P<POINTER>\*)'
COMMA = r'(?P<COMMA>\,)'
SEMICOLON = r'(?P<SEMICOLON>\;)'

VOID=r'(?P<VOID>void)'
INT = r'(?P<INT>int)'
LEFT=r'(?P<LEFT>\()'
RIGHT=r'(?P<RIGHT>\))'
L2 = r'(?P<L2>\[)'
R2 = r'(?P<R2>\])'
WS = r'(?P<WS>\s+)'

COMMENT = r'(?P<COMMENT>//[^\r\n]*|/\*.*?\*/)'
master_pat = re.compile('|'.join([LEFT,RIGHT,L2,R2,POINTER,COMMA,SEMICOLON,INT,VOID,NUM, WS,NAME]),re.DOTALL)

class Token:
    def __init__(self,tp,val):
        self.type = tp
        self.value = val
    def __repr__(self):
        return '({},"{}")'.format(self.type,self.value)
def gen_token(text):
    scanner = master_pat.scanner(text)
    for m in iter(scanner.match,None):
        if m.lastgroup!='WS':
            yield Token(m.lastgroup,m.group())
if __name__ =='__main__':
    while 1:
        expr = input('>> ')
        for i in gen_token(expr):
            print(i)

