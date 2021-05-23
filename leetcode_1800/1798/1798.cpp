#include "utils.h"

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(ALL(coins));
        int cur=0;
        for(int a:coins){
            if(a>cur+1)break;
            cur+=a;
        }
        return cur;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi coins{1,3};
    auto ans=sol.getMaximumConsecutive(coins);
    DBG(ans);

    system("pause");
    return 0;
}
