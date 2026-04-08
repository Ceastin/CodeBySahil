class Solution:
    def isPalindrome(self, x: int) -> bool:
        xx=x
        d=0
        while xx>0:
            d=d*10+xx%10
            xx=xx//10
        print(d)
        print(x)
        return x==d
        