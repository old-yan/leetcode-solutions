#include "utils.h"

class Solution {
public:
    int uniqueLetterString(string s) {
        ll ans=0;
        REP(i,s.size()){
            int pre=s.find_last_of(s[i],i);
            int next=s.find_first_of(s[i],i);
            if(next<0)next=s.size();
            ans=(ans+(ll)(i-pre)*(next-i))%MOD;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="ABA";
    auto ans=sol.uniqueLetterString(s);
    DBG(ans);

    system("pause");
    return 0;
}
