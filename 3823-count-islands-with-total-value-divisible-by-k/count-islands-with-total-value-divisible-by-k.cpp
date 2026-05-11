class Solution {
public:
    int fnc(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int kk)
    {
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        int r[4]={0,1,-1,0};
        int c[4]={1,0,0,-1};
        long long ans=grid[i][j];
        for(int k=0;k<4;k++)
        {
            int tr=i+r[k];
            int tc=j+c[k];
            if(tr>=0&&tr<n&&tc>=0&&tc<m&&vis[tr][tc]==0&&grid[tr][tc]!=0)
            ans=(ans+fnc(tr,tc,grid,vis,kk)%kk)%kk;
        }
        return ans%kk;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        long long ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0&&vis[i][j]==0)
                {
                    int sum=fnc(i,j,grid,vis,k);
                    if(sum%k==0)
                    ans++;
                }
            }
        }
        return ans;

    }
};