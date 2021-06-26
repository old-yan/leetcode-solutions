#include "utils.h"

class Solution {
public:
    int leastMinutes(int n) {
        int ans=INT_MAX;
        for(int i=0,cur=1;i<20;i++,cur<<=1){
            chmin(ans,i+(n+cur-1)/cur);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    auto ans=sol.leastMinutes(n);
    DBG(ans);

    system("pause");
    return 0;
}
