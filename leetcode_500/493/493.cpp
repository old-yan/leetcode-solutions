#include "utils.h"

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
        unordered_map<int,int>M;
        REP(i,rnk.size())M[nums[i]]=rnk[i];
        SegTree<int> T(M.size(),0,[](int x,int y){return x+y;});
        int ans=0;
        REPR(i,n-1){
            ans+=T(0,M[half(nums[i])]);
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
