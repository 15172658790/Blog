import sympy
import numpy as np
from math import sqrt


def newton(y:sympy.core,x0:float,epsilon:float=0.00001,maxtime:int=50) ->(list,list):
    '''
        newton 's iteration method for finding a zeropoint of a func
        y is the func, x0 is the init x val: int float epsilon is the accurrency
    '''
    if epsilon <0:epsilon = -epsilon
    ct =0
    t =  y.free_symbols
    varsymbol = 'x' if len(t)==0 else t.pop()
    x0= float(x0)
    y_diff = y.diff()
    li = [x0]
    vals = []
    while 1:
        val = y.subs(varsymbol,x0)
        vals.append(val)
        x = x0- val/y_diff.subs(varsymbol,x0)
        li.append(x)
        ct+=1
        if ct>maxtime:
            print("after iteration for {} times, I still havn't reach the accurrency.\
                    Maybe this function havsn't zeropoint\n".format(ct))
            return li ,val
        if abs(x-x0)<epsilon:return li,vals
        x0 = x
        

def secant(y:sympy.core,x0:float,x1:float,epsilon:float =0.00001,maxtime:int=50) ->(list,list):
    '''
        弦截法, 使用newton 差商计算,每次只需计算一次f(x)
        secant method for finding a zeropoint of a func
        y is the func , x0 is the init x val,     epsilon is the accurrency
    '''
    if epsilon <0:epsilon = -epsilon
    ct =0
    x0,x1 = float(x0),float(x1)
    li = [x0,x1]
    t =  y.free_symbols
    varsymbol = 'x' if len(t)==0 else t.pop()
    last = y.subs(varsymbol,x0)
    vals = [last]
    while 1:
        cur = y.subs(varsymbol,x1)
        vals.append(cur)
        x = x1-cur*(x1-x0)/(cur-last)
        x0 ,x1= x1,x
        last = cur
        li.append(x)
        ct+=1
        if ct>maxtime:
            print("after iteration for {} times, I still havn't reach the accurrency.\
                    Maybe this function havsn't zeropoint\n".format(ct))
            return li,vals
        if abs(x0-x1)<epsilon:return li,vals
        x0 = x


def solveNonlinearEquations(funcs:[sympy.core],init_dic:dict,epsilon:float=0.001,maxtime:int=50)->dict:
    '''solve  nonlinear equations:'''
    li = list(init_dic.keys())
    delta = {i:0 for i in li}
    ct = 0
    while 1:
        ys = np.array([f.subs(init_dic) for f in funcs],dtype = 'float')
        mat = np.matrix([[i.diff(x).subs(init_dic) for x in li] for i in funcs ],dtype = 'float')
        delt = np.linalg.solve(mat,-ys)
        for i,j in enumerate(delt):
            init_dic[li[i]] +=j
            delta[li[i]] = j
        if ct>maxtime:
            print("after iteration for {} times, I still havn't reach the accurrency.\
                    Maybe this function havsn't zeropoint\n".format(ct))
            return init_dic
        if sqrt(sum(i**2 for i in delta.values()))<epsilon:return init_dic


if __name__ =='__main__':
    x,y,z = sympy.symbols('x y z')
    
    res,res2= newton(x**5-9,2,0.01)
    print(res,res2)


    res,res2 = secant (x**3-3*x-2,1,3,1e-3)
    print(res,res2)


    funcs=[x**2+y**2-1,x**3-y]
    init = {x:0.8,y:0.6}
    res_dic = solveNonlinearEquations(funcs,init,0.001)
    print(res_dic)
