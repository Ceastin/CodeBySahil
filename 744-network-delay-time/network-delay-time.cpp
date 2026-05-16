class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> v(n+1);
        for(auto it:times)
        {
            v[it[0]].push_back({it[1],it[2]});
        }
        unordered_set<int> st;
        priority_queue<vector<int>> pq;
        pq.push({0,k});
        int maxi=-1;
        vector<int> vis(n+1);
        vis[k]=1;
        while(!pq.empty())
        {
            int cost=pq.top()[0];
            int node=pq.top()[1];
            pq.pop();
            if(vis[node]<cost)
            continue;
            st.insert(node);
            for(auto it:v[node])
            {
                if(vis[it.first]==0||vis[it.first]>(cost+it.second))
                {
                    pq.push({cost +it.second,it.first});
                    vis[it.first]=it.second+cost;
                }
            }
        }
        if(st.size()!=n)
        return -1;
        for(int i=1;i<=n;i++)
        {
            maxi=max(maxi,vis[i]);
        }
        return maxi;
    }
};