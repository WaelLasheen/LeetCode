class Solution:
    def myPow(self, x: float, n: int) -> float:
        if not n:
            return 1
        if n==1:
            return x

        if n<0:
            x= 1/x
            n =-n
        
        res = self.myPow(x ,n//2)

        if n&1:
            return res*res*x

        return res*res