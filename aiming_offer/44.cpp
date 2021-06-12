#include "utils.h"

class Solution {
public:
    int findNthDigit(int n) {
        if(!n)return 0;
        int w=1;
        while(true){
            ll num=9*pow(10,w-1);
            if(w*num<n){
                n-=w++*num;
                continue;
            }
            string s=i2s(pow(10,w-1)+(n-1)/w);
            return s[(n-1)%w]-'0';
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=100;
    auto ans=sol.findNthDigit(n);
    DBG(ans);

    system("pause");
    return 0;
}
