#include "utils.h"

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size()!=s2.size())return false;
        string s=s2+s2;
        return int(s.find(s1))>=0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="waterbottle";
    string s2="erbottlewat";
    auto ans=sol.isFlipedString(s1,s2);
    DBG(ans);

    system("pause");
    return 0;
}
