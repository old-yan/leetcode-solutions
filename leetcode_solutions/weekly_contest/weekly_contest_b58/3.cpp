#include "utils.h"
#include "SegTree.h"

class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int n=nums.size();
        //get_seg 函数辅助计算当在[l,r]区间不进行调整的情况下，在这一区间最少浪费多少空间
        //显然，该值为区间最大值×区间长度-区间和
        //但是这样计算会导致时间复杂度很高，所以我们需要一些数据结构对这个过程进行预处理

        //区间最大值：可以使用st表，猫树，O(1)的查询时间
        //区间和：可以使用猫树，O(1)的查询时间
        //此处，我们可以退而求其次，使用线段树，虽然查询的时间复杂度比较差，为 O(logn) ，但是也可以过
        static SegTree<int>sum_T(100000,[](int x,int y){return x+y;});
        static SegTree<int>max_T(100000,[](int x,int y){return x>y?x:y;});
        sum_T.set(nums);
        max_T.set(nums);
        auto get_seg=[&](int l,int r){
            //return *max_element(nums.begin()+l,nums.begin()+r+1)*(r-l+1)-accumulate(nums.begin()+l,nums.begin()+r+1,0);
            return max_T(l,r)*(r-l+1)-sum_T(l,r);
        };

        //不妨令 dp[i][j] 表示 截止下标i，进行j次调整的最小浪费
        ll dp[n][k+1];
        memset(dp,0x3f,sizeof(dp));
        //dp[i][j]可以由dp[pre][j-1] 加上 [pre+1,i]这段区间的浪费值转移而来
        //注意循环嵌套顺序，最外层i，中间pre，内层j
        //为什么呢，因为i和pre可以确定seg值，这里算出来之后，最内层就没必要每次都计算了
        REP(i,n){
            dp[i][0]=get_seg(0,i);
            REP(pre,i){
                ll seg=get_seg(pre+1,i);
                FOR(j,1,k+1){
                    chmin(dp[i][j],dp[pre][j-1]+seg);
                }
            }
        }
        return dp[n-1][k];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{10,20,15,30,20};
    int k=2;
    auto ans=sol.minSpaceWastedKResizing(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
