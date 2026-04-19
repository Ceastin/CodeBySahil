class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi=0;
        for(int i=0;i<nums2.size();i++)
        {
            int l=0;
            int r=min(i,(int)nums1.size()-1);
            int ans=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(nums1[mid]<=nums2[i])
                {
                    ans=mid;
                    r=mid-1;
                }
                else
                l=mid+1;
            }
            if(ans!=-1)
            {
                maxi=max(maxi,i-ans);
            }
        }
        return maxi;
    }
};