class Solution {
public:
    int fnc(vector<int> temp,map<vector<int>,int>& mp, unordered_map<int,vector<int>>& r,unordered_map<int,vector<int>>& c)
    {
        mp[temp]=1;
        int rr=temp[0];
        int cc=temp[1];
        int ans=0;
        for(auto it:r[rr])
        {
            if(!mp.count({rr,it}))
            ans=ans+1+fnc({rr,it},mp,r,c);
        }
        for(auto it:c[cc])
        {
            if(!mp.count({it,cc}))
            ans=ans+1+fnc({it,cc},mp,r,c);
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        map<vector<int>,int> mp;
        unordered_map<int,vector<int>> r,c;
        for(auto it:stones)
        {
            r[it[0]].push_back(it[1]);
            c[it[1]].push_back(it[0]);
        }
        int ans=0;
        for(auto it:stones)
        {
            if(!mp.count(it))
            {
                int tm=fnc(it,mp,r,c);
                ans=ans+tm;
            }
        }
        return ans;
    }
};