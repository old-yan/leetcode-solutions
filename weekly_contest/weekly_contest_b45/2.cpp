#include "utils.h"

class Solution {
public:
    //绝对值最大，要么是正的很大，要么是负的很小
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=0;
        //sum记录前缀和
        vi sum{0};
        for(int a:nums)sum.pb(sum.back()+a);
        //afterMax记录sum数组某个位置之后的最大值
        int afterMax[sum.size()];
        REPR(i,sum.size())afterMax[i]=i==sum.size()?sum[i]:max(sum[i],afterMax[i]);
        //afterMin记录sum数组某个位置之后的最小值
        int afterMin[sum.size()];
        REPR(i,sum.size())afterMin[i]=i==sum.size()?sum[i]:min(sum[i],afterMin[i]);
        REP(i,nums.size()){
            //可能会正的很大
            chmax(ans,abs(afterMax[i]-sum[i]));
            //可能会负的很小
            chmax(ans,abs(afterMin[i]-sum[i]));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,-5,1,-4,3,-2};
    auto ans=sol.maxAbsoluteSum(nums);
    DBG(ans);

    system("pause");
    return 0;
}
