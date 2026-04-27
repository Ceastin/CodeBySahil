class Solution {
public:
    vector<vector<vector<int>>> mp{
        {
            {0,-1},{0,1}
        },{
            {1,0},{-1,0}
        },{
            {0,-1},{1,0}
        },{
            {0,1},{1,0}
        },{
            {-1,0},{0,-1}
        },{
            {-1,0},{0,1}
        }
    };
    bool ok(int i,int j,int ni,int nj,vector<vector<int>>& grid){
    int val = grid[ni][nj] - 1;
    for(auto &d: mp[val]){
        if(ni + d[0] == i && nj + d[1] == j)
            return true;
    }
    return false;
}
    bool fnc(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1&&j==m-1)
        return true;
        if(i<0||j<0||i>=n||j>=m)
        return false;
        int val=grid[i][j]-1;
        if(vis[i][j]==1)
        return false;
        vis[i][j]=1;
        int i1=mp[val][0][0]+i;
        int j1=mp[val][0][1]+j;
        int i2=mp[val][1][0]+i;
        int j2=mp[val][1][1]+j;
        bool op1=false;
        if(i1>=0&&i1<n&&j1>=0&&j1<m && ok(i,j,i1,j1,grid))
        {
            if(fnc(i1,j1,grid,vis)) return true;
        }

        if(i2>=0&&i2<n&&j2>=0&&j2<m && ok(i,j,i2,j2,grid))
        {
            if(fnc(i2,j2,grid,vis)) return true;
        }

        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        return fnc(0,0,grid,vis);
    }
};