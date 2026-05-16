class Solution {
public:
    unordered_map<string,int> mp;
    vector<int> par;
    int fnc(int node)
    {
        return par[node]==node?node:par[node]=fnc(par[node]);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        par.resize(n);
        iota(par.begin(),par.end(),0);
        int c=0;
        for(auto it:accounts)
        {
            for(int i=1;i<it.size();i++)
            {
                if(mp.count(it[i]))
                {
                    int pa=fnc(mp[it[i]]);
                    int pait=fnc(c);
                    par[pait]=pa;
                }
                mp[it[i]]=c;
            }
            c++;
        }
        map<int,set<string>> mps;
        for(int i=0;i<n;i++)
        {
            int node=fnc(i);
            for(int j=1;j<accounts[i].size();j++)
            {
                mps[node].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> temp;
        for(auto [a,b]:mps)
        {
            vector<string> ans;
            ans.push_back(accounts[a][0]);
            for(auto i:b)
            {
                ans.push_back(i);
            }
            temp.push_back(ans);
        }
        return temp;

    }
};