#include "utils.h"

class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        //用n来表示剩余天数，当n>0时可以继续
        for(int start=1;n>0;start++){
            for(int i=0;i<7&&n>0;i++){
                ans+=(start+i);
                n--;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=500;
    auto ans=sol.totalMoney(n);
    DBG(ans);

    system("pause");
    return 0;
}
