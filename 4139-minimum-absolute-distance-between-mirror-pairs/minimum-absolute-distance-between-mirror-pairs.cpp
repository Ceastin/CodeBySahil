class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(nums[i]))
            {
                mini=min(mini,abs(i-mp[nums[i]]));
            }
            int x=nums[i];
            int NX=0;
            while(x>0)
            {
                NX=NX*10+x%10;
                x=x/10;
            }
            mp[NX]=i;
        }
        return mini==INT_MAX?-1:mini;
    }
};