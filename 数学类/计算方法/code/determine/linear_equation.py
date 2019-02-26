#########################################################################
# File : linear_equation.py
# Author: mbinary
# Mail: zhuheqin1@gmail.com
# Blog: https://mbinary.xyz
# Github: https://github.com/mbinary
# Created Time: 2018-05-20  08:36
# Description:   书上p186 附录1 程序11
#########################################################################

import numpy as np

def gauss_prior_elimination(A,b=None):
    '''using guass elimination,get up_trianglge form of A'''
    m,n = A.shape
    res = [0]*m if b is None else b
    if m!=n:raise Exception("[Error]: matrix is not inversable")
    B = np.matrix(A,dtype=float) # necessary,otherwise when the dtype of A is int, then it will be wrong
    for  i in range(m-1):
        col = abs(B[i:,i]) #  note using abs value,  return a matrix in (m-i)x1 form
        mx = col.max()
        if mx==0: raise Exception("[Error]: matrix is not inversable")
        pos = i+col.argmax()
        if pos != i :  B[[pos,i],:] = B[[i,pos],:]  #  note how to swap cols/rows
        #B[i,:] = B[i,:]/mx
        #res[i]/=mx
        for j in range(i+1,m):
            if B[j,i]!=0:
                B[j,:] -= B[j,i]/B[i,i] * B[i,:]
                res[j] -= res[i]/B[i,i]*res[j]
    if b is None:return B
    return B,res

def det(A):
    m,n = A.shape
    ret=1
    B = gauss_prior_elimination(A)
    for i in range(m):ret *= B[i,i]
    return ret

def test(A):
    print()
    print('计算行列式')
    print(A)
    print('我的结果: det(A) = ',det(A))
    print('函数调用: det(A) = ',np.linalg.det(A))
if __name__ == '__main__':
    A = np.matrix([[10,5,0,0],
                     [2,2,1,0],
                     [0,10,0,5],
                      [0,0,2,1]])
    test(A)

    A = np.matrix([[-6,3,2],
                     [3,5,1],
                     [2,1,6]])
    test(A)
