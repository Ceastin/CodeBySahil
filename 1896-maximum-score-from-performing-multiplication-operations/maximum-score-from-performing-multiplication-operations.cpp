class Solution {
public: 
    vector<vector<int>> dp;
    int fnc(int l,int i,vector<int>& nums,vector<int>& multipliers)
    {
        if(i==multipliers.size())
        return 0;
        if(dp[l][i]!=INT_MIN)
        return dp[l][i];
        int n=nums.size();
        int r=n-1-(i-l);
        return dp[l][i]=max(nums[l]*multipliers[i]+fnc(l+1,i+1,nums,multipliers),nums[r]*multipliers[i]+fnc(l,i+1,nums,multipliers));
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        dp.resize((int)nums.size(),vector<int>(multipliers.size(),INT_MIN));
        return fnc(0,0,nums,multipliers);
    }
};