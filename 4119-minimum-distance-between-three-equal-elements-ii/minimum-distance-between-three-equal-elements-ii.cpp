class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        int mini=INT_MAX;
        for(auto it:mp)
        {
            if(it.second.size()<3)
            continue;
            for(int i=2;i<it.second.size();i++)
            {
                mini=min(mini,abs(it.second[i-2] - it.second[i-1]) + abs(it.second[i-1] - it.second[i]) + abs(it.second[i] - it.second[i-2]));
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};