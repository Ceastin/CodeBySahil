class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(in[i]==0)
            q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            ans.push_back(i);
            for(auto it:adj[i])
            {
                in[it]--;
                if(in[it]==0)
                q.push(it);
            }
        }
        if(ans.size()!=numCourses)return{};
        return ans;
    }
};