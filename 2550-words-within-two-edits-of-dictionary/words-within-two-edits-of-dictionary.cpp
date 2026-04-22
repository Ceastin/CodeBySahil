class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=(int)queries[0].size();
        vector<string>ans;
        for(int i=0;i<(int)queries.size();i++)
        {
            for(int j=0;j<(int)dictionary.size();j++)
            {
                int c=0;
                bool found=false;
                for(int k=0;k<n;k++)
                {
                    if(queries[i][k]!=dictionary[j][k])
                    c++;
                    if(c>2)
                    break;
                }
                if(c<=2)
                found=true;
                if(found)
                {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};