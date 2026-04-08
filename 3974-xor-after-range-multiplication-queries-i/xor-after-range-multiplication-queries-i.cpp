class Solution {
public:
    const int mod=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++)
        {
            int j=queries[i][0];
            int r=queries[i][1];
            int jump=queries[i][2];
            int val=queries[i][3];
            for(;j<=r;j+=jump)
            {
                nums[j]=((long long)nums[j]*val)%mod;
            }
        }
        int valX=0;
        for(auto it:nums)
        valX^=it;
        return valX;
    }
};