#include "utils.h"

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int digit[31];
        REP(i,31){
            digit[i]=n%2;
            n/=2;
        }
        int make10[31],make00[31],make00from10[31],make10from00[31];
        make10[0]=digit[0]==1?0:1;
        make00[0]=digit[0]==0?0:1;
        make00from10[0]=1;
        make10from00[0]=1;
        for(int i=1;i<31;i++){
            make00from10[i]=make10from00[i-1]+1+make00from10[i-1];
            make10from00[i]=make10from00[i-1]+1+make00from10[i-1];
            if(digit[i]==1){
                make10[i]=make00[i-1];
                make00[i]=make10[i-1]+1+make00from10[i-1];
            }
            else{
                make10[i]=make10[i-1]+1+make00from10[i-1];
                make00[i]=make00[i-1];
            }
        }
        return make00[30];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    auto ans=sol.minimumOneBitOperations(n);
    DBG(ans);

    system("pause");
    return 0;
}
