class Solution {
public:
    vector<vector<vector<int>>> dp;
    int fnc(int i,int j,vector<vector<int>>& grid,int k)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1&&j==m-1&&k>=0)
        {
            int tocut=grid[i][j]==0?0:1;
            if(k-tocut>=0)
            return dp[k][i][j]=grid[i][j];
            return dp[k][i][j]=INT_MIN/2;
        }
        if(i>=n||j>=m||k<0)
        return INT_MIN/2;
        if(dp[k][i][j]!=INT_MIN)
        return dp[k][i][j];
        int tocut=grid[i][j]==0?0:1;
        return dp[k][i][j]=grid[i][j]+max(fnc(i+1,j,grid,k-tocut),fnc(i,j+1,grid,k-tocut));
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        dp.assign(k+1,vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),INT_MIN)));
        int ans=fnc(0,0,grid,k);
        if(ans<0)
        return -1;
        return ans;
    }
};