#include "utils.h"

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vi v[26];
        REP(i,s.size()){
            v[s[i]-'a'].pb(i);
        }
        int ans=-1;
        REP(i,26)if(v[i].size()){
            chmax(ans,v[i].back()-v[i].front()-1);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abca";
    auto ans=sol.maxLengthBetweenEqualCharacters(s);
    DBG(ans);

    system("pause");
    return 0;
}
