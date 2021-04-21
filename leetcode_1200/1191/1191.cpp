#include "utils.h"

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        ll sum=accumulate(ALL(arr),0ll);
        ll res=0;
        auto presum=arr;
        partial_sum(ALL(presum),presum.begin());
        ll a=max(0,*max_element(ALL(presum)));
        chmax(res,a);
        auto postsum=arr;
        partial_sum(ALLR(postsum),postsum.rbegin());
        ll b=max(0,*max_element(ALL(postsum)));
        chmax(res,b);
        if(k>1){
            chmax(res,sum*(k-2)+a+b));
            chmax(res,a+b);
        }
        {
            int Min=0;
            for(int a:presum){
                chmax(res,(ll)a-Min);
                chmin(Min,a);
            }
        }
        return res%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,-2,1};
    int k=5;
    auto ans=sol.kConcatenationMaxSum(arr,k);
    DBG(ans);

    system("pause");
    return 0;
}
