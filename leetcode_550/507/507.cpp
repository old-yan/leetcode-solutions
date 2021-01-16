#include "utils.h"

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int cnt=0;
        FOR(i,1,sqrt(num)){
            if(num%i==0)cnt+=i+num/i;
        }
        if(num==sqrt(num)*sqrt(num))cnt+=sqrt(num);
        return cnt==num*2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=28;
    auto ans=sol.checkPerfectNumber(num);
    DBG(ans);

    system("pause");
    return 0;
}
