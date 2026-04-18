class Solution {
public:
    int N;
    int fnc(int n,int copy)
    {
        if(n==N)
        return 0;
        if(n>N)
        return INT_MAX/2;
        return min(2+fnc(n*2,n),1+fnc(n+copy,copy));
    }
    int minSteps(int n) {
        N=n;
        if(n==1)
        return 0;
        return 1+fnc(1,1);
    }
};