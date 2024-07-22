class Solution:
    def countGoodNumbers(self, n: int) -> int:
        # it's diffcult to do in cpp
        # need to immplement function by my self
        odd = n//2
        even = n-odd
        mod = 1000000007
        return (pow(5,even,mod)*pow(4,odd,mod))%mod