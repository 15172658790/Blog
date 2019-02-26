from random import randint,random
import numpy as np
from operator import neg,and_
from functools import reduce


class  obj():
    def __init__(self,data):
        self.data=np.array(data)
    def __add__(self,x):
        data =  x.data if self.__class__ == x.__class__ else x
        return self.__class__(self.data + data)
    def __radd__(self,x):
        data =  x.data if self.__class__ == x.__class__ else x
        return self.__class__(data +self.data)
    def __iadd__(self,x):
        data =  x.data if self.__class__ == x.__class__ else x
        self.data += data
    def __mul__(self,x):
        data =  x.data if self.__class__ == x.__class__ else x
        return self.__class__(self.data * data)
    def __imul__(self,x):
        data =  x.data if self.__class__ == x.__class__ else x
        self.data *= data
    def __rmul__(self,x):
        data =  x.data if self.__class__ == x.__class__ else x
        return self.__class__(data * self.data)
    def __neg__(self):
        return neg(self)
    def __abs__(self):
        return abs(self.data)
    '''
    @property
    def data(self):
        return self.data
    @data.setter
    def data(self,s):
        self.data = s
    '''
    def norm(self,n=0):
        '''the default is +oo norm'''
        absolute = abs(self.data)
        if n < 1 :return max(absolute)
        return (sum(absolute**n))**(1/n)
    def hasNorm(self):
        '''check norm's three necessary conditions:
            1. not neg
            2. homogenious (qici)
            3. triangle  inequlity
    
            there is much probably wrong
        '''
        bl = reduce(and_,[self.norm(i)>=0 for i in range(3)])
        if bl:
            n  = randint(2,100)
            bl = reduce(and_,[n*(self.norm(i))==(n*self).norm(i) for i in range(3)])
            if bl:
                another  = self*randint(2,10)-randint(1,100)
                return reduce(and_,[(another+self).norm(i)<=another.norm(i)+self.norm(i) for i in range(3)])
        return False
    
class vector(obj):
    def __init__(self,arr):
        ''' arr: iterable'''
        self.data =np.array(arr)
    def innerProduct(self,x):
        return sum(self.data*x)
    def outerProduct(self,x):
        pass


class matrix(obj):
    def __init__(self,s):
        '''s is a list of lists'''
        self.data=np.mat(s)
        self.T = None
        self. I = None
    '''
    @property
    def T(self):
        if self.T==None:self.T = self.data.T
        return self.T
    @T.setter
    def T(self,s):
        self.T = s
    @property
    def I(self):
        if self.I == None: self.I = self.data.I
        return self.I

    @I.setter
    def I(self,s):
        self.I = s
    '''
    def E(self,n=None):
        if n is None: n = self.data.shape[0]
        return np.eye(n)

    def norm(self,n=0):
        absolute  = abs(self.data)
        if n < 1:
            # max of one row sum
            return max([sum(i) for i in absolute])
        if n==1:return self.norm1()
        elif n==2:return self.norm2()
    def norm1(self):
        ''' max of sum of cols'''
        absolute = abs(self.data)
        return max(absolute.sum(axis=0))  
    def norm2(self):
        ''' max of sum of rows'''
        absolute = abs(self.data)
        return max(absolute.sum(axis=1))
    def norm_f(self):
        return sum((self.data**2).sum(axis=1))**0.5

if __name__ =='__main__':
    v1 = vector([1,-2,3,4])
    v2 = vector([0,2,0,5])
    m1 = matrix([v1,v2,v2,v1])
    print([v1.norm(i) for i in range(3)])
    
