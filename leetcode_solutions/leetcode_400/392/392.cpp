#include "utils.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int next[t.size()+2][26];
        memset(next,0xff,sizeof(next));
        REPR(i,t.size()){
            REP(j,26){
                if(j==t[i]-'a')next[i][j]=i+1;
                else next[i][j]=next[i+1][j];
            }
        }
        int idx=0;
        REP(i,s.size()){
            idx=next[idx][s[i]-'a'];
            if(idx<0)return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abc";
    string t="ahbgdc";
    auto ans=sol.isSubsequence(s,t);
    DBG(ans);

    system("pause");
    return 0;
}
