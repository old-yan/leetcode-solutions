#include "utils.h"

class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans=0;
        REP(i,s.size())REP(j,t.size())if(s[i]!=t[j]){
            int left,right;
            for(left=1;i-left>=0&&j-left>=0&&s[i-left]==t[j-left];left++);
            for(right=1;i+right<s.size()&&j+right<t.size()&&s[i+right]==t[j+right];right++);
            ans+=left*right;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aba";
    string t="baba";
    auto ans=sol.countSubstrings(s,t);
    DBG(ans);

    system("pause");
    return 0;
}
