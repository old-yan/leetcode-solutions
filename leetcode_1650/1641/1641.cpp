#include "utils.h"

auto table=combinationTable(50,5);
class Solution {
public:
    int countVowelStrings(int n) {
        int ans=0;
        FOR(appear,1,6){
            ans+=(ll)table[5][appear]*table[n-1][appear-1];
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    auto ans=sol.countVowelStrings(n);
    DBG(ans);

    system("pause");
    return 0;
}
