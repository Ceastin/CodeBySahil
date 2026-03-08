class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int pos=-1;
        int mini=INT_MAX;
        for(int i=0;i<capacity.size();i++)
            {
                if(capacity[i]>=itemSize && capacity[i]<mini){
                    pos=i;
                    mini=capacity[i];
                }
            }
        return pos;
    }
};