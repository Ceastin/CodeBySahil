class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            int ind=queries[i];
            int x=nums[ind];
            if(mp[x].size()==1)
            ans.push_back(-1);
            else
            {
                auto& vec=mp[x];
                int k=vec.size();
                int pos=lower_bound(vec.begin(),vec.end(),ind)-vec.begin();
                int next=vec[(pos+1)%k];
                int prev=vec[(pos-1+k)%k];
                int d1=abs(ind-next);
                d1=min(d1,n-d1);
                int d2=abs(ind-prev);
                d2=min(d2,n-d2);
                ans.push_back(min(d1,d2));
            }
        }
        return ans;
    }
};