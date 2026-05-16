class Solution {
public:
    class dsu{
        public:
        vector<int> par;
        vector<int> sz;
        dsu(int n)
        {
            par.resize(n);
            sz.resize(n,1);
            iota(par.begin(),par.end(),0);
        }
        int parent(int node)
        {
            return node==par[node]?par[node]:par[node]=parent(par[node]);
        }
        void ubsz(int u,int v){
            int pu=parent(u);
            int pv=parent(v);
            if(pu==pv)
            return ;
            if(sz[pv]>sz[pu])
            swap(pu,pv);
            par[pv]=pu;
            sz[pu]+=sz[pv];
        }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1;
        dsu d(n);
        int ans=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            d.ubsz(u,v);
        }  
        for(int i=0;i<n;i++)
        {
            int pi=d.parent(i);
            if(pi==i)
           ans++;
        }
        return ans-1;
    }
};