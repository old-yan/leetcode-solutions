#include "utils.h"

class Solution {
public:
    string generateTheString(int n) {
        if(n%2)return string(n,'a');
        else return "a"+string(n-1,'b');
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.generateTheString(n);
    DBG(ans);

    system("pause");
    return 0;
}
