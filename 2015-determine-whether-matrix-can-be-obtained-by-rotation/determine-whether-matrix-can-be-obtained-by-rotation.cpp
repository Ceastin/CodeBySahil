class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> mat90=mat,mat180=mat;
        for(int i=1;i<mat.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                int temo=mat90[i][j];
                mat90[i][j]=mat90[j][i];
                mat90[j][i]=temo;
            }
        }
        for(int i = 0; i < mat90.size(); i++) {
        reverse(mat90[i].begin(), mat90[i].end());
        }
        reverse(mat180.begin(),mat180.end());
        for(int i=0;i<mat180.size();i++)
        {
            reverse(mat180[i].begin(),mat180[i].end());
        }
        vector<vector<int>> mat270=mat90;

        reverse(mat270.begin(),mat270.end());
        for(int i=0;i<mat.size();i++)
        {
           reverse(mat270[i].begin(),mat270[i].end());
        }
        
        
        return target==mat90||target==mat180||target==mat270||target==mat;
    }
};