class Solution {
public:
    int fnc(int i,int j,int k,vector<vector<int>>& coins,vector<vector<vector<int>>>& dp)
    {
        if(i==coins.size()-1&&j==coins[0].size()-1)
        {
            if(coins[i][j]>=0)
            return coins[i][j];
            else if(k>0)
            return 0;
            else return coins[i][j];
        }
        if(dp[i][j][k]!=INT_MIN)
        return dp[i][j][k];
        int op1=INT_MIN,op2=INT_MIN;
        if(coins[i][j]>=0){
            if(i+1<coins.size()&&j<coins[0].size())
            op1=coins[i][j]+fnc(i+1,j,k,coins,dp);
            if(i<coins.size()&&j+1<coins[0].size())
            op2=coins[i][j]+fnc(i,j+1,k,coins,dp);
        }
        else
        {
            if(k>0)
            {
                if(i+1<coins.size()&&j<coins[0].size())
                op1=max(0+fnc(i+1,j,k-1,coins,dp),coins[i][j]+fnc(i+1,j,k,coins,dp));
                if(i<coins.size()&&j+1<coins[0].size())
                op2=max(0+fnc(i,j+1,k-1,coins,dp),coins[i][j]+fnc(i,j+1,k,coins,dp));
            }
            else
             {
                if(i+1<coins.size()&&j<coins[0].size())
                op1=coins[i][j]+fnc(i+1,j,k,coins,dp);
                if(i<coins.size()&&j+1<coins[0].size())
                op2=coins[i][j]+fnc(i,j+1,k,coins,dp);
             }
        }
        return dp[i][j][k]=max(op1,op2);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>> dp(coins.size(),vector<vector<int>>(coins[0].size(),vector<int>(3,INT_MIN)));
        return fnc(0,0,2,coins,dp);
    }
};