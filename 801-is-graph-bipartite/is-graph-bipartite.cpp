class Solution {
public:
    bool fnc(int i,int color,vector<int>& vis,vector<vector<int>>& graph)
    {
        vis[i]=color;
        for(auto it:graph[i])
        {
            if(vis[it]==-1)
            {
                if(fnc(it,!color,vis,graph)==false)
                return false;
            }else {
                if(vis[it]==color)return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                ans=ans&&fnc(i,0,vis,graph);
            }
        }
        return ans;
    }
};