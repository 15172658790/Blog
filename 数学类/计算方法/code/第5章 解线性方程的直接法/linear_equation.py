
#coding: utf-8
'''************************************************************************
    > File Name: doolittle.py
    > Author: mbinary
    > Mail: zhuheqin1@gmail.com 
    > Blog: https://mbinary.xyz
    > Created Time: 2018-04-20  08:32
 ************************************************************************'''

import numpy
def getLU(A):
    '''doolittle :     A = LU, 
        L is in  down-triangle form, 
        U is in  up-triangle form
    '''
    m,n = A.shape
    if m!=n:raise Exception("this matrix is not inversable")

    L = numpy.zeros([m,m])
    U = numpy.zeros([m,m])
    L = numpy.matrix(L)
    U = numpy. matrix(U)
    U[0] = A[0]
    L[:,0] = A[:,0] / A[0,0]
    for i in range(1,m):
        for j in range(i,m):
            U[i,j]= A[i,j] - sum(L[i,k]*U[k,j] for k in range(i))
            L[j,i] = (A[j,i] - sum(L[j,k]*U[k,i] for k in range(i)))/U[i,i]
    print(L)
    print(U)
    return L,U


def solveDown(A,b):
    '''A is a matrix in down-triangle form'''
    sol = numpy.zeros(b.shape)
    for i in range(b.shape[0]):
        sol[i,0] = (b[i,0]-sum(A[i,j]*sol[j,0] for j in range(i)))/A[i,i]
    return sol

def solveUp(A,b):
    '''A is a matrix in up-triangle form'''
    sol = numpy.zeros(b.shape)
    n = b.shape[0]
    for i in range(n-1,-1,-1):
        sol[i,0] = (b[i,0]-sum(A[i,j]*sol[j,0] for j in range(n-1,i,-1)))/A[i,i]
    return sol
def doolittle(A,b):
    L,U = getLU(A)
    y = solveDown(L,b)
    x = solveUp(U,y)
    print(y)
    print(x)
    return x
def ldlt(A,b):
    L,U = getLU(A)
    D = numpy.diag(numpy.diag(U))
    print(D,"D")
    z = numpy.linalg.solve(L,b)
    print(z,"z")
    y = numpy.linalg.solve(D,z)
    print(y,"y")
    x = numpy.linalg.solve(L.T,y)
    print(x,"x")
    return x
if __name__ == '__main__':
    
    A = numpy.matrix([[10,5,0,0],
                     [2,2,1,0],
                     [0,1,10,5],
                      [0,0,2,1]])
    b = numpy.matrix([[5],[3],[27],[6]])
    x  = numpy.linalg.solve(A,b)
    print(x)

    '''ldlt
    A = numpy.matrix([[-6,3,2],
                     [3,5,1],
                     [2,1,6]])
    b = numpy.matrix([[-4],[11],[-8]])
    ldlt(A,b)
    '''
'''
    A = numpy.matrix([[2,1,1],
                     [1,3,2],
                     [1,2,2]])
    b = numpy.matrix([[4],[6],[5]])
    doolittle(A,b)
'''
    
