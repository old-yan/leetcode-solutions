#include "SegTree.h"
#include "utils.h"

SegTree<int>T(30001,[](int x,int y){return x+y;});
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<ll>copy(ALL(nums));
        partial_sum(ALL(copy),copy.begin());
        unordered_map<ll,int>M;
        {
            vector<ll> ma{0};
            for(ll a:copy){
                ma.pb(a);
                ma.pb(a-lower);
                ma.pb(a-upper);
            }
            vi rnk=getrank2(ma);
            REP(i,rnk.size())M[ma[i]]=rnk[i];
        }
        T.set(0);
        int ans=0;
        T.step_forward(M[0]);
        for(ll a:copy){
            ans+=T(M[a-upper],M[a-lower]);
            T.step_forward(M[a]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-2,0,1,-1};
    int lower=1;
    int upper=4;
    auto ans=sol.countRangeSum(nums,lower,upper);
    DBG(ans);

    system("pause");
    return 0;
}
