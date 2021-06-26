#include "utils.h"

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        sort(ALL(s1));
        sort(ALL(s2));
        return s1==s2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="abc";
    string s2="bca";
    auto ans=sol.CheckPermutation(s1,s2);
    DBG(ans);

    system("pause");
    return 0;
}
