#include "utils.h"

class Solution {
public:
    int minimumBoxes(int n) {
        ll cur=0,bottom=0,a,b;
        for(a=0;;a++){
            for(b=0;b<=a;b++){
                cur+=b+1;
                bottom++;
                if(cur>=n)return bottom;
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=100;
    auto ans=sol.minimumBoxes(n);
    DBG(ans);

    system("pause");
    return 0;
}
