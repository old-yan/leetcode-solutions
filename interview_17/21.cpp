#include "utils.h"

class Solution {
public:
    int trap(vector<int>& height) {
        auto preMax=premax(height);
        auto postMax=postmax(height);
        int ans=0;
        REP(i,height.size()){
            ans+=min(preMax[i],postMax[i])-height[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi height{0,1,0,2,1,0,1,3,2,1,2,1};
    auto ans=sol.trap(height);
    DBG(ans);

    system("pause");
    return 0;
}
