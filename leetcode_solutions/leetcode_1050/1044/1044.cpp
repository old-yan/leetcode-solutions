#include "SuffixArray.h"
#include "utils.h"

class Solution {
public:
    string longestDupSubstring(string s) {
        SuffixArray<> sa(s);
        sa.getHeight();
        int ans=max_element(sa.height,sa.height+s.size())-sa.height;
        return s.substr(sa.sa[ans],sa.height[ans]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="banana";
    auto ans=sol.longestDupSubstring(s);
    DBG(ans);

    system("pause");
    return 0;
}
