class Solution:
    def reverse(self, x: int) -> int:
        flag=False
        if x<0:
            x=abs(x)
            flag=True
        d=0
        while x>0:
            d=d*10+x%10
            x=x//10
        if flag:
            d=-d
        if d < -2**31 or d > 2**31 - 1:
            return 0
        return d

        