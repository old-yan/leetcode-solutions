#include "utils.h"

class Solution {
public:
    int numberOf2sInRange(int n) {
        if(n<2)return 0;
        else if(n<12)return 1;
        auto res=numberOf2sInRange(n/10-1)*10+n/10;
        FOR(i,n/10*10,n+1){
            for(int j=i;j;j/=10)res+=j%10==2;
        }
        return res;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=25;
    auto ans=sol.numberOf2sInRange(n);
    DBG(ans);

    system("pause");
    return 0;
}
