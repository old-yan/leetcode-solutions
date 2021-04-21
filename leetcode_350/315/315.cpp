#include "SegTree.h"
#include "utils.h"

SegTree<int>T(20001,[](int x,int y){return x+y;});
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int Min=*min_element(ALL(nums));
        for(int&a:nums)a-=Min;
        vi ans(nums.size(),0);
        T.set(0);
        REPR(i,nums.size()-1){
            int j=nums[i];
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
