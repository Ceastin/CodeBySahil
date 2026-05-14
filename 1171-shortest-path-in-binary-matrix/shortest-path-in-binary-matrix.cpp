class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1||grid[n-1][m-1]==1)
        return -1;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({1,0,0});
        vector<vector<int>> vis(n,vector<int>(m,1e9));
        vis[0][0]=1;
        int r[8]={1,0,-1,0,-1,1,1,-1};
        int c[8]={0,1,0,-1,1,-1,1,-1};
        while(!pq.empty())
        {
            int dist=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();
            if(vis[x][y]<dist)continue;
            if(x==n-1&&y==m-1)
            return dist;
            for(int i=0;i<8;i++)
            {
                int tr=x+r[i];
                int tc=y+c[i];
                if(tr>=0&&tr<n&&tc>=0&&tc<m&&vis[tr][tc]>dist+1&&grid[tr][tc]==0)
                {
                    vis[tr][tc]=dist+1;
                    pq.push({dist+1,tr,tc});
                }
            }
        }
        return -1;
    }
};