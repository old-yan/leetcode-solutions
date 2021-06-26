#include "utils.h"

class Solution {
public:
    //分析问题，我们发现，对答案有影响的，是nums1和nums2的对应关系。只要配对关系不变，哪对在前哪对在后根本无关紧要
    //所以对nums1我们可以不管它的顺序
    //问题变为：寻找一种nums2的排列，使得和nums1对应之后，每一对的异或值的和最小
    //数值范围很小，可以使用状态压缩结合动态规划
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        //dp[mask]表示把mask代表的nums2的元素靠前放，所能取得的最小异或和
        int dp[1<<n];
        dp[0]=0;
        FOR(mask,1,1<<n){
            dp[mask]=INT_MAX;
            //k为mask中二进制1的数量，表示mask要和nums1的前k个数字配对
            int k=__builtin_popcount(mask);
            //枚举mask中的每个1，令其作为和nums1[k-1]的配对者，剩余的1和nums1[0~k-2]配对
            REP(j,n)if(mask>>j&1){
                chmin(dp[mask],dp[mask-(1<<j)]+(nums1[k-1]^nums2[j]));
            }
        }
        return dp[(1<<n)-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{1,0,3};
    vi nums2{5,3,4};
    auto ans=sol.minimumXORSum(nums1,nums2);
    DBG(ans);

    system("pause");
    return 0;
}
