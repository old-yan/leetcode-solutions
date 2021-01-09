#include "utils.h"

class Solution {
public:
    int integerReplacement(int _n) {
        int ans=0;
        ll n=_n;
        while(n>1){
            ans++;
            if(n%2==0)n>>=1;
            else if((n&2)&&n>3)n++;
            else n--;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=733;
    auto ans=sol.integerReplacement(n);
    DBG(ans);

    system("pause");
    return 0;
}
