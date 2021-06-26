#include "SegTree.h"
#include "utils.h"

SegTree<int>T(101,[](int x,int y){return x+y;});
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        T.set(0);
        for(int a:nums)T.step_forward(a);
        for(int&a:nums)a=T(0,a-1);
        return nums;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{8,1,2,2,3};
    auto ans=sol.smallerNumbersThanCurrent(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
