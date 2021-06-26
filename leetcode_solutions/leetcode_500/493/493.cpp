#include "SegTree.h"
#include "utils.h"

SegTree<int>T(100000,[](int x,int y){return x+y;});
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        auto half=[](ll val){
            return val>0?(val-1)/2:(val-2)/2;
        };
        int n=nums.size();
        REP(i,n){
            nums.pb(half(nums[i]));
        }
        vi rnk=getrank2(nums);
        int ans=0;
        T.set(0);
        REPR(i,n-1){
            ans+=T(0,rnk[i+n]);
            T.step_forward(rnk[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,3,2,3,1};
    auto ans=sol.reversePairs(nums);
    DBG(ans);

    system("pause");
    return 0;
}
