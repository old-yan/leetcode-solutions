#include "utils.h"

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans=1;
        FOR(i,1,n+1){
            int count=1;
            int rest=10;
            REPR(j,i-1){
                if(j==i-1)count*=9;
                else count*=rest;
                rest--;
            }
            ans+=count;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=8;
    auto ans=sol.countNumbersWithUniqueDigits(n);
    DBG(ans);

    system("pause");
    return 0;
}
