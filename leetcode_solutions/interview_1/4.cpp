#include "utils.h"

class Solution {
public:
    bool canPermutePalindrome(string s) {
        bool b[128]={0};
        for(char c:s)b[c]=!b[c];
        return count(b,b+128,true)<2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="tactcoa";
    auto ans=sol.canPermutePalindrome(s);
    DBG(ans);

    system("pause");
    return 0;
}
