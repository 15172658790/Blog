import sympy
from collections import namedtuple
from functools import reduce
from operator import mul

X = sympy.Symbol ('x')
point = namedtuple('point',['x','y'])

class interplotion:
    def __init__(self,points):
        self.points  = [point(x,y) for x,y in points]
        self.xs= [i for i,j in points]
        self.poly,self.rem = self.newton(self.points,0,len(self.points)-1)

    def newton(self,li,a,b):
        '''li:[(x,f(x))...]'''
        
        qs = [li[0].y]
        
        def quoDiff(begin,end):
            if begin == end:return li[begin].y
            q = (quoDiff(begin+1,end)-quoDiff(begin,end-1))/(li[end].x-li[begin].x)
            if begin == a:qs.append(q)
            return q

        quoDiff(a,b)
        poly ,base = 0, 1
        for i,q  in enumerate(qs):
            poly += q*base
            base*= X-li[i].x
        return poly, base*qs[-1]
    def lagrange(self,points=None):
        xs = None
        if points is None:
            xs = self.xs
            points = self.points
        else: xs =[x for x,y in points]
        product = reduce(mul,[X-x  for x in xs],1)
        poly = 0
        for x,y in points:
            tmp  = product/(X-x)
            coef = y/(tmp.subs(X,x))
            poly+= coef *tmp
        return poly
    
    def predict(self,val,poly = None):
        if poly is None:poly = self.poly
        return poly.subs(X,val) #  note the func  subs


if __name__ == '__main__':
    f = interplotion([(81,9),(100,10),(121,11)])
    p = f.lagrange()
    print(p.subs(X,105))
    print(p)
