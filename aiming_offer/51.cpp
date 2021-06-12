#include "SegTree.h"
#include "utils.h"

SegTree<int>T(50000,[](int x,int y){return x+y;});
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        auto rnk=getrank2(nums);
        T.set(0);
        ll ans=0;
        for(int a:rnk){
            ans+=T(a+1,rnk.size()-1);
            T.step_forward(a);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{7,5,6,4};
    auto ans=sol.reversePairs(nums);
    DBG(ans);

    system("pause");
    return 0;
}
