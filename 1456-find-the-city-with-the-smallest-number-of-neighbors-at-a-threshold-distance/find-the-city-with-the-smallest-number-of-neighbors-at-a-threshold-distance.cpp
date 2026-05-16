class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> v(n);
        for(auto it:edges)
        {
            v[it[0]].push_back({it[1],it[2]});
            v[it[1]].push_back({it[0],it[2]});
        }
        int ans=-1;
        int maxi=1e9;
        for(int i=0;i<n;i++)
        {
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
            pq.push({0,i});
            unordered_set<int> st;
            vector<int> dist(n,1e9);
            while(!pq.empty())
            {
                int dis=pq.top()[0];
                int node=pq.top()[1];
                st.insert(node);
                pq.pop();
                if(dist[node]<dis)
                continue;
                for(auto it:v[node])
                {
                    int nnoe=it.first;
                    int di=it.second;
                    int ne=di+dis;
                    if(di+dis<=distanceThreshold&&dist[nnoe]>di+dis)
                    {
                        pq.push({di+dis,nnoe});
                        dist[nnoe]=di+dis;
                    }
                }
            }
            if(maxi==(int)st.size())
            {
                if(i>ans)
                ans=i;
            }
            if(maxi>(int)st.size())
            {
                ans=i;
                maxi=(int)st.size();
            }
        }
        return ans;
    }
};