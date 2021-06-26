#include "utils.h"

class Solution {
public:
    bool checkPowersOfThree(int n) {
        for(int i=pow(3,15);i;i/=3){
            if(n>=i)n-=i;
        }
        return !n;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=91;
    auto ans=sol.checkPowersOfThree(n);
    DBG(ans);

    system("pause");
    return 0;
}
