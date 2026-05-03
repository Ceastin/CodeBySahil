class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal)
        return true;
        for(int i=0;i<s.size();i++)
        {
            string temp=s.substr(i);
            cout<<temp<<" ";
            string ss=temp+s.substr(0,i);
            cout<<ss<<endl;
            if(ss==goal)
            return true;
        }
        return false;
    }
};