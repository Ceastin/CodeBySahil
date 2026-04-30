class Solution {
public:
    vector<int> dp;
    int fnc(int sh,int i,vector<vector<int>>& books)
    {
        if(i>=books.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int jj=i;
        int ss=sh;
        int cur=0;
        int ans=INT_MAX;
        while(i<books.size()&&ss>0&&books[i][0]<=ss)
        {
            cur=max(cur,books[i][1]);
            ss-=books[i][0];
            ans=min(ans,cur+fnc(sh,i+1,books));
            i++;
        }
        return dp[jj]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        dp.resize(books.size(),-1);
        return fnc(shelfWidth,0,books);
    }
};