#include "utils.h"

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vi target=heights;
        sort(ALL(target));
        int ans=0;
        REP(i,target.size()){
            if(heights[i]!=target[i])ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi heights{1,1,4,2,1,3};
    auto ans=sol.heightChecker(heights);
    DBG(ans);

    system("pause");
    return 0;
}
