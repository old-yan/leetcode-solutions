#include "utils.h"

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        auto sum=presum(nums);
        vi rank=getrank2(sum);
        map<ll,int>M;
        REP(i,rank.size()){
            M[sum[i]]=rank[i];
        }
        M[LLONG_MAX]=INT_MAX;
        zkwTree T(rank.size());
        T.step(rank[0]);
        int ans=0;
        FOR(i,1,rank.size()){   
            auto it=M.lower_bound(sum[i]-upper);
            auto it2=M.lower_bound(sum[i]-lower+1);
            ans+=T(it->second,it2->second-1);
            T.step(rank[i]);
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
