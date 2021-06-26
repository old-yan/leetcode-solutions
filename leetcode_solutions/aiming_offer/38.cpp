#include "utils.h"

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string>ans;
        sort(ALL(s));
        do{
            ans.pb(s);
        }while(next_permutation(ALL(s)));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abc";
    auto ans=sol.permutation(s);
    DBGV(ans);

    system("pause");
    return 0;
}
