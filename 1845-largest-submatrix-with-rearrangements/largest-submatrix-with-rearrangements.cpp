class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        for(int i=matrix[0].size()-1;i>=0;i--)
        {
            int c=0;
            for(int j=matrix.size()-1;j>=0;j--)
            {
                if(matrix[j][i]==0)
                c=0;
                else
                c+=matrix[j][i];
                matrix[j][i]=c;
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            sort(matrix[i].begin(),matrix[i].end());
        }
        int ans=-1e9;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                ans=max({ans,((int)matrix[0].size()-j)*matrix[i][j]});
            }
        }
        return ans;
    }
};