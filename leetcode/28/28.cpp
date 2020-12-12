#include "utils.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string haystack="hello";
    string needle="";
    auto ans=sol.strStr(haystack,needle);
    DBG(ans);

    system("pause");
    return 0;
}
