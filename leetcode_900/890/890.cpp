#include "utils.h"

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(string&s:words){
            int s2p[26]={0};
            int p2s[26]={0};
            bool b=true;
            REP(i,pattern.size()){
                char c1=s[i],c2=pattern[i];
                if(s2p[c1-'a']&&s2p[c1-'a']!=c2)b=false;
                s2p[c1-'a']=c2;
                if(p2s[c2-'a']&&p2s[c2-'a']!=c1)b=false;
                p2s[c2-'a']=c1;
            }
            if(b)ans.pb(s);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{"abc","deq","mee","aqq","dkd","ccc"};
    string pattern="abb";
    auto ans=sol.findAndReplacePattern(words,pattern);
    DBGV(ans);

    system("pause");
    return 0;
}
