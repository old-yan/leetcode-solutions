#include "utils.h"

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        auto sum=presum(nums);
        int n=sum.size();
        REP(i,n){
            sum.pb(sum[i]-lower);
            sum.pb(sum[i]-upper);
        }
        vi rnk=getrank2(sum);
        unordered_map<int,int>M;
        REP(i,rnk.size())M[sum[i]]=rnk[i];
        SegTree<int> T(M.size(),0,[](int x,int y){return x+y;});
        int ans=0;
        REP(i,n){  
            ans+=T(M[sum[i]-upper],M[sum[i]-lower]);
            T.step_forward(rnk[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0};
    int lower=0;
    int upper=0;
    auto ans=sol.countRangeSum(nums,lower,upper);
    DBG(ans);

    system("pause");
    return 0;
}
