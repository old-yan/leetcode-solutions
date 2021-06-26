#include "utils.h"

class Solution {
public:
    //本题看数据范围，大概率为状态压缩
    //不妨令dp[i]为i所表示的状态所能凑出的最大分数
    //例如：dp[1010101011]表示nums[0],nums[1],nums[3],nums[5],nums[7],nums[9]所能凑出的最大分数
    //dp的转移方式为：任取某两个二进制的1，将这两个1凑一对，作为最后取的一对
    //例如：dp[1010101011]=dp[0000101011]+3*gcd(nums[7],nums[9])   是一种可能的转移
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        ll dp[1<<n];
        memset(dp,0,sizeof(dp));
        for(int state=1;state<(1<<n);state++){
            //如果当前状态的二进制下1的个数为奇数，那它就不是一种合法状态，跳过
            if(__builtin_popcount(state)%2)continue;
            //如果合法，那么先算出总共要取多少轮（多少对）
            int turn=__builtin_popcount(state)/2;
            //枚举子集，如果子集的二进制的1有两个，就让这两个来作为最后一对
            for(int s=state;s;s=(s-1)&state){
                if(__builtin_popcount(s)==2){
                    //利用库函数计算，用a和b表示两个1所在的下标
                    int a=__builtin_ctz(s),b=31-__builtin_clz(s);
                    dp[state]=max(dp[state],dp[state-s]+turn*gcd(nums[a],nums[b]));
                }
            }
        }
        return dp[(1<<n)-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4,5,6};
    auto ans=sol.maxScore(nums);
    DBG(ans);

    system("pause");
    return 0;
}
