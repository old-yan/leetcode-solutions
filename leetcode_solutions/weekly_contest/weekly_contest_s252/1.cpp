#include "utils.h"

class Solution {
public:
    //简单模拟
    bool isThree(int n) {
        int ans=0;
        for(int i=1;i<=n;i++)
            if(n%i==0)ans++;
        return ans==3;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    auto ans=sol.isThree(n);
    DBG(ans);

    system("pause");
    return 0;
}
