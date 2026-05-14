class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> ans(n,vector<int>(m,1e9));
        pq.push({0,0,0});
        ans[0][0]=0;
        int r[4]={1,0,-1,0};
        int c[4]={0,1,0,-1};
        while(!pq.empty())
        {
            vector<int> temp=pq.top();
            int h=temp[0];
            int x=temp[1];
            int y=temp[2];
            pq.pop();
            if(h>ans[x][y])
            continue;
            if(x==n-1&&y==m-1)
            return h;
            for(int i=0;i<4;i++)
            {
                int tr=x+r[i];
                int tc=y+c[i];
                if(tr>=0&&tr<n&&tc>=0&&tc<m&&(ans[tr][tc]==1e9||ans[tr][tc]>max(h,abs(heights[x][y]-heights[tr][tc]))))
                {
                    ans[tr][tc]=max(h,abs(heights[x][y]-heights[tr][tc]));
                    pq.push({ans[tr][tc],tr,tc});
                }
            }
        }
        return -1;
    }
};