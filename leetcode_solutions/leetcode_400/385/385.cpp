#include "utils.h"

class Solution {
public:
    NestedInteger deserialize(string s) {
        return makenestedinteger(s);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="[123,[456,[789]]]";
    auto ans=sol.deserialize(s);
    DBG(ans);

    system("pause");
    return 0;
}
