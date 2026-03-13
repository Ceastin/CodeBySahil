class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number=0;
        for(auto it:nums)
        number^=it;
        return number;
    }
};