#include "utils.h"

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        //cur表示当前高度
        int cur=0;
        for(int a:gain){
            cur+=a;
            ans=max(ans,cur);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi gain{-4,-3,-2,-1,4,3,2};
    auto ans=sol.largestAltitude(gain);
    DBG(ans);

    system("pause");
    return 0;
}
