#include "utils.h"

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size()!=b.size())return max(a.size(),b.size());
        if(a==b)return -1;
        return a.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string a="abc";
    string b="abcd";
    auto ans=sol.findLUSlength(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
