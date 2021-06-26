#include "utils.h"

class Solution {
public:
    vector<string> permutation(string S) {
        vector<string>ans;
        sort(ALL(S));
        do{
            ans.pb(S);
        }while(next_permutation(ALL(S)));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="qwe";
    auto ans=sol.permutation(S);
    DBGV(ans);

    system("pause");
    return 0;
}
