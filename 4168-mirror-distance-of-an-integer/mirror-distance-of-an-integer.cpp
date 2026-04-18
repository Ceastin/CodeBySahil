class Solution {
public:
    int mirrorDistance(int n) {
        int s=0;
        int nn=n;
        while(nn>0)
        {
            int d=nn%10;
            nn/=10;
            s=s*10+d;
        }
        return abs(n-s);
    }
};