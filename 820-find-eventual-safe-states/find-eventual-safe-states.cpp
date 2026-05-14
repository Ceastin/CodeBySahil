class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> in(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i]){
                in[i]++;
                adj[it].push_back(i);
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++)
        if(in[i]==0)
        q.push(i);
        while(!q.empty())
        {
            int val=q.front();
            q.pop();
            ans.push_back(val);
            for(auto it:adj[val])
            {
                in[it]--;
                if(in[it]==0)
                q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};