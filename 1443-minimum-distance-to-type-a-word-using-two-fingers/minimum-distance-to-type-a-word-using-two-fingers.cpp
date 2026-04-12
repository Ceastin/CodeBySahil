class Solution {
public:
    map<tuple<int,int,int,int,int>, int> dp;
    int fnc(string& word,int i,int x1,int y1,int x2,int y2)
    {
        if(i>=word.size())
        return 0;
        int val=word[i]-'A';
        int x=val/6;
        int y=val%6;
        if(dp.count({i,x1,y1,x2,y2}))
        return dp[{i,x1,y1,x2,y2}];
        if(i==0)
        {
            return dp[{i,x1,y1,x2,y2}]=min(0+fnc(word,i+1,x,y,x2,y2)
            ,0+fnc(word,i+1,x1,y1,x,y));
        }
        else
        {
            int op1=INT_MAX/2;
            int op2=INT_MAX/2;
            if(x2==-1)
            {
                op1=0+fnc(word,i+1,x1,y1,x,y);
                op2=abs(x1-x)+abs(y1-y)+fnc(word,i+1,x,y,x2,y2);
            }
            else{
                op2=min(abs(x1-x)+abs(y1-y)+fnc(word,i+1,x,y,x2,y2),abs(x2-x)+abs(y2-y)+fnc(word,i+1,x1,y1,x,y));
            }
            
            return dp[{i,x1,y1,x2,y2}]=min(op1,op2);
        }
    }
    int minimumDistance(string word) {
        return fnc(word,0,-1,-1,-1,-1);
    }
};