'''*************************************************************************
    > File Name: least-square.py
    > Author: mbinary
    > Mail: zhuheqin1@gmail.com 
    > Created Time: Sat 07 Apr 2018 09:55:25 PM DST
    > Blog: https://mbinary.xyz
 ************************************************************************'''

import re
import numpy as np



def solveConflitEqualtion(A,y):
    '''solve equation like this: Av = y,  
        A:m*n  v:n*1  y:m*1 
        return vector v
    '''
    A = np.matrix(A)
    y = np.array(y)
    ata = A.T*A
    print('AtA')
    print(ata)
    return np.linalg.solve(ata,A.T*y) # note that is numpy.linalg.solve 

def solveLinear(point,index):
    y = [[i[1]] for i in point]
    x = [[i[0]] for i in point]
    A = []
    for i in x:
        A.append([i[0]**j for j in index])
    res =  solveConflitEqualtion(A,y)
    print('the solution is : \n',res)
    print('namely: ')
    items = ['{:.4f}x^{}'.format(res[i,0],j)   for i, j in enumerate(index)]
    print('phi(x) = ',' + '.join(items))

def handleInput(s=None,y=None):
    # numPt = re.compile (r'\d*\.{0,1}\d+')
    if not s: s = input('input matrix A:m*n  //m>=n\n')
    s = s.replace(' ','')
    li = re.findall(r'(\[(\d+)(,(\d+))+\])',s)
    li = [parseLst(i[0]) for i in li] 
    if not y:y = input('input a vector y:n*1\n')
    y = parseLst(y)
    print('Equation: Av = y:')
    
    print('y is as follows: ')
    print(y)
    print('A is as follows: ')
    for i in li:
        for j in i:
            print('{}'.format(j).rjust(5),end='')
        print('')
    
    print('result v is as follows: ')
    res = solveConflitEqualtion(li,y)
    print(res)
def parseLst(s):
    s = s.strip('[]') 
    li = s.split(',')
    li = [float(j) for j in li]
    return li


if __name__ == '__main__':
    '''
    li = '[[23,2],[2,5],[2,6]]'
    y = '[1,3]'
    while True:
        handleInput(li,y)
        s = input('input y to continue, n for exit')
        if s!='y':break
    '''
    point = [(-3,14.3),(-2,8.3),(-1,4.7),(2,-8.3),(4,-22.7)]
    lst = [0,3]
    solveLinear(point,lst)

    point= [(-3,14.3),(-2,8.3),(-1,4.7),(2,8.3),(4,22.7)]
    lst = [0,2]
    solveLinear(point,lst)
    
    A = [[1,2],[2,1],[1,1]]
    y  = [[5],[6],[4]]
    res = solveConflitEqualtion(A,y)
    
    print(res)
    A = [[1,-2],[1,5],[2,1],[1,1]]
    y = [[1],[13.1],[7.9],[5.1]]
    print(solveConflitEqualtion(A,y))
