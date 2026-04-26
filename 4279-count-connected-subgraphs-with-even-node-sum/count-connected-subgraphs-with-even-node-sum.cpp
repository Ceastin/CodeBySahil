class Solution {
public: 
    unordered_map<int,vector<int>> mp;
    void help(int i,int p, int& state)
    {
        if((1<<i)&state){
            state&=~(1<<i);
        }
        else return ;
        for(auto &it:mp[i]){
            if(p!=it){
                help(it,i,state);
            }
        }
    }
    bool check(int state)
    {
        if(!state) return false;
        int s=0;
        for(int i=0;i<=13;i++)
        {
            if((1<<i)&state){
                s=i;
                break;
            }
        }
        help(s,-1,state);
        return state==0;
    }
    int solve(vector<int>& nums,int i,int state,int tot)
    {
        if(i>=nums.size())
        {
            return (tot%2==0)&&check(state);
        }
        int ans=0;
        int newstate=(1<<i)|state;
        ans+=solve(nums,i+1,newstate,tot+nums[i]);
        ans+=solve(nums,i+1,state,tot);
        return ans;
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int state=0;
        for(auto &it:edges)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        return solve(nums,0,state,0);
    }
};