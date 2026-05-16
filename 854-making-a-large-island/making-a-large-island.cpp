class Solution {
public:
    vector<vector<int>> v;
    int fnc(int i,int j,vector<vector<int>>& grid,int kk)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size())
        return 0;
        v[i][j]=kk;
        int r[4]={0,0,-1,1};
        int c[4]={1,-1,0,0};
        int ans=1;
        for(int k=0;k<4;k++)
        {
            int rr=r[k]+i;
            int cc=c[k]+j;
            if(rr>=0&&rr<grid.size()&&cc>=0&&cc<grid[0].size()&&v[rr][cc]==-1&&grid[rr][cc]==1)
            {
                ans=ans+fnc(rr,cc,grid,kk);
            }
        }
        return ans;

    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        v.resize(n,vector<int>(m,-1));
        int c=0;
        unordered_map<int,int> mp;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1&&v[i][j]==-1)
                {
                    int ans=fnc(i,j,grid,c);
                    mp[c]=ans;
                    maxi=max(maxi,ans);
                    c++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    unordered_set<int> st;
                    int r[4]={0,0,-1,1};
                    int c[4]={1,-1,0,0};
                    for(int k=0;k<4;k++)
                    {
                        int rr=r[k]+i;
                        int cc=c[k]+j;
                        if(rr>=0&&rr<n&&cc>=0&&cc<m&&grid[rr][cc]==1)
                        st.insert(v[rr][cc]);
                    }
                    int temp=0;
                    for(auto it:st)
                    {
                        temp+=mp[it];
                    }
                    maxi=max(maxi,temp+1);
                }
            }
        }
        return maxi;
        

    }
};