#include "utils.h"

class Solution {
public:
    int balancedStringSplit(string s) {
        vi v;
        for(char c:s)v.pb(c=='L'?1:-1);
        partial_sum(ALL(v),v.begin());
        int zero=0;
        for(int a:v)zero+=!a;
        return zero;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="RLLLLRRRLR";
    auto ans=sol.balancedStringSplit(s);
    DBG(ans);

    system("pause");
    return 0;
}
