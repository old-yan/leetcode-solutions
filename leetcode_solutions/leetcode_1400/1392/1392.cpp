#include "SuffixArray.h"
#include "utils.h"

class Solution {
public:
    string longestPrefix(string s) {
        return s.substr(0,getnext(s+"*").back());
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="level";
    auto ans=sol.longestPrefix(s);
    DBG(ans);

    system("pause");
    return 0;
}
