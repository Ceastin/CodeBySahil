class Solution {
public:
    
    int minimumDistance(vector<int>& nums) {
        int maxi=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    for(int k=j+1;k<nums.size();k++)
                    {
                        if(nums[k]==nums[i])
                            maxi=min(maxi,abs(i - j) + abs(j - k) + abs(k - i));
                    }
                }
            }
        }
        return maxi==INT_MAX?-1:maxi;
    }
};