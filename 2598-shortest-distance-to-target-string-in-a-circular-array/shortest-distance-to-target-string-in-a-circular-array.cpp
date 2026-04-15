class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int mini=INT_MAX;
        int n=words.size();
        for(int i=0;i<words.size();i++)
        {
            if(words[i]==target)
            {
                if(i<startIndex)
                {
                    mini=min(mini,startIndex-i);
                    mini=min(mini,abs(((startIndex-i)-n)%n));
                }
                else{
                    mini=min(mini,i-startIndex);
                    mini=min(mini,abs(((i-startIndex)-n)%n));
                }
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};