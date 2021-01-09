#include "utils.h"

class Solution {
public:
    int findNthDigit(int n) {
        int i=1,cnt=0;
        while(true){
            if(cnt+9*pow(10,i-1)*i>=n)break;
            cnt+=9*pow(10,i-1)*i++;
        }
        return i2s(pow(10,i-1)+(n-cnt-1)/i)[(n-cnt-1)%i]-'0';
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=11;
    auto ans=sol.findNthDigit(n);
    DBG(ans);

    system("pause");
    return 0;
}
