#include "utils.h"

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        SegTree<int>T(nums.size(),0,[](int x,int y){return x+y;});
        vi rnk=getrank2(nums);
        vi ans(rnk.size(),0);
        REPR(i,rnk.size()-1){
            int j=rnk[i];
            ans[i]=T(0,j-1);
            T.step_forward(j);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,2,6,1};
    auto ans=sol.countSmaller(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
