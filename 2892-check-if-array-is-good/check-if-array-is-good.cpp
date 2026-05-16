class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]-1!=i)
            return false;
        }
        if(nums.back()!=n)
        return false;
        return true;
    }
};