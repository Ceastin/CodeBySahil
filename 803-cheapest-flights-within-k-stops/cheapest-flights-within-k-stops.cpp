class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<int>> dist(n,vector<int>(k+2,-1));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,src,k+1});
        for(int i=0;i<=k;i++)
        {
            dist[src][i]=0;
        }
        while(!pq.empty())
        {
            int node=pq.top()[1];
            int kk=pq.top()[2];
            int cost=pq.top()[0];
            pq.pop();
            if(node==dst)
            return cost;
            if(kk==0)
            continue;
            // if(dist[node][kk]<=cost)
            // continue;
            for(auto it:adj[node])
            {
                int to=it.first;
                int add=cost+it.second;
                cout<<to<<" "<<add<<" "<<kk<<endl;
                if(dist[to][kk]==-1||dist[to][kk]>add)
                {
                    dist[to][kk]=add;
                    pq.push({add,to,kk-1});
                }
            }
        }
        return -1;
    }
};