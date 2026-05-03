class Solution {
public:
    int rotatedDigits(int n) {
        unordered_map<int,int> mp,mp1;
        mp[2]=1;
        mp[5]=1;
        mp[6]=1;
        mp[9]=1;
        int ans=0;
        mp1[3]=1;
        mp1[4]=1;
        mp1[7]=1;
        for(int i=1;i<=n;i++)
        {
            int n=i;
            bool op1=false;
            bool op2=false;
            while(n>0)
            {
                int d=n%10;
                n=n/10;
                if(mp.count(d))
                op1=true;
                if(mp1.count(d))
                op2=true;
            }
            if(op1&&!op2)
            ans++;
        }
        return ans;
    }
};