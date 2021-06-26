#include "utils.h"

class Solution {
public:
    int countDigitOne(int n) {
        if(n<10)return n>=1;
        else{
            int res=countDigitOne(n/10-1)*10+n/10;
            do{
                for(int a=n;a;a/=10)res+=a%10==1;
            }while(n--%10);
            return res;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=100;
    auto ans=sol.countDigitOne(n);
    DBG(ans);

    system("pause");
    return 0;
}
