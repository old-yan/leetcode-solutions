#include "utils.h"

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n)+s.substr(0,n);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abcdefg";
    int k=2;
    auto ans=sol.reverseLeftWords(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
