#include "utils.h"

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()!=B.size())return false;
        return int((A+A).find(B))>=0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string A="abcde";
    string B="cdeab";
    auto ans=sol.rotateString(A,B);
    DBG(ans);

    system("pause");
    return 0;
}
