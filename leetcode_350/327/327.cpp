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
        T.set(rank[0],T[rank[0]]+1);
        int ans=0;
        FOR(i,1,rank.size()){   
            auto it=M.lower_bound(sum[i]-upper);
            auto it2=M.lower_bound(sum[i]-lower+1);
            ans+=T(it->second,it2->second-1);
            T.set(rank[i],T[rank[i]]+1);
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
