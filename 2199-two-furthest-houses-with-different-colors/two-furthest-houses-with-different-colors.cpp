class Solution {
public:
    int maxDistance(vector<int>& colors) {
        pair<int,int> f={colors[0],0},s={-1,-1};
        int ans=0;
        for(int i=0;i<colors.size();i++)
        {
            if(f.first==colors[i])
            {
                if(s.first!=-1)
                {
                    ans=max(ans,abs(i-s.second));
                }
            }
            else
            {
                if(s.first==-1)
                {
                    s={colors[i],i};
                }
                ans=max(ans,abs(i-f.second));   
            }
        }
        return ans;
    }
};