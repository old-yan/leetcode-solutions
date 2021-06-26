#include "SegTree.h"
#include "utils.h"

SegTree<ll>T1(100000,[](ll x,ll y){return x+y;}),T2(100000,[](ll x,ll y){return x+y;});
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        T1.set(0);
        T2.set(0);
        int Max=*max_element(ALL(packages));
        for(int a:packages){
            T1.step_forward(a);
            T2.step(a,a);
        }
        ll ans=LLONG_MAX;
        for(auto&box:boxes){
            sort(ALL(box));
            if(box.back()<Max)continue;
            int pre=0;
            ll cnt=0;
            for(int b:box){
                cnt+=T1(pre+1,b)*b-T2(pre+1,b);
                pre=b;
            }
            chmin(ans,cnt);
        }
        return ans==LLONG_MAX?-1:ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi packages{2,3,5};
    vvi boxes=makevvi("[[4,8],[2,8]]");
    auto ans=sol.minWastedSpace(packages,boxes);
    DBG(ans);

    system("pause");
    return 0;
}
