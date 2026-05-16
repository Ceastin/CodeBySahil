class Solution {
public:
    int findMin(vector<int>& nums) {
     int mini=1e9;
     for(auto it:nums)
     mini=min(mini,it);
     return mini;   
    }
};