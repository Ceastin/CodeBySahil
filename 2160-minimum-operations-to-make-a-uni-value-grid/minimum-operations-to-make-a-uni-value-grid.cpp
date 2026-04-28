class Solution {
public:
    int check(int mid,vector<int>& ans,int x)
    {
        int val=ans[mid];
        int calc=0;
        for(int i=0;i<ans.size();i++)
        {
            if(abs(ans[i]-val)%x==0)
            calc+=(abs(ans[i]-val)/x);
            else return -1;
        }
        return calc;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> ans;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                ans.push_back(grid[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()%2==0)
        {
            int op1=check(ans.size()/2,ans,x);
            int op2=check(ans.size()/2-1,ans,x);
            return min(op1,op2)==-1?max(op1,op2):min(op1,op2);
        }
        else
        {
            return check(ans.size()/2,ans,x);
        }
    }
};