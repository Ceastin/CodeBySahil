class Solution {
public:
    int r[4]={0,1,0,-1};
    int c[4]={1,0,-1,0};
    bool fnc(vector<vector<int>>& vis,vector<vector<char>>& grid,int val,int i,int j,int col)
    {
        vis[i][j]=val;
        bool ans=false;
        for(int k=0;k<4;k++)
        {
            int rr=r[k]+i;
            int cc=c[k]+j;
            if(rr<0||rr>=grid.size()||cc<0||cc>=grid[0].size())
            continue;
            if(grid[rr][cc]==col&&vis[rr][cc]!=-1)
            {
                if(val-vis[rr][cc]>=3)
                return true;
            }
            else if(grid[rr][cc]==col)
            {
                ans=ans||fnc(vis,grid,val+1,rr,cc,col);
                if(ans)
                return true;
            }
        }
        return ans;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        bool ans=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==-1)
                {
                    ans=ans||fnc(vis,grid,0,i,j,grid[i][j]);
                    if(ans)return true;
                }
            }
        }
        return false;
    }
};