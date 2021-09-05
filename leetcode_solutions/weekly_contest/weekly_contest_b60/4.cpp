#include "utils.h"

class Solution {
    static constexpr int base[10]={2,3,5,7,11,13,17,19,23,29};
    //本函数检查[2,30]范围内的数字是否合法：即这个数字是否不含重复的因数
    bool valid(int n){
        for(int b:base){
            if(n%b==0)n/=b;
        }
        return n==1;
    }
    //如果合法，那么可以将这个数字转换为一个压缩的二进制数字，表示它含有哪些base
    int getmask(int n){
        int mask=0;
        for(int i=0;i<10;i++){
            if(n%base[i]==0){
                mask|=1<<i;
            }
        }
        return mask;
    }
public:
    //本题把哪些带平方数的数字筛掉之后只剩下20个左右的数字，所以直接回溯是可行的
    //这里介绍一下状态压缩+动态规划的做法
    int numberOfGoodSubsets(vector<int>& nums) {
        int cnt[31]={0};
        for(int a:nums)cnt[a]++;
        //总计有2^10种状态，每种状态表示子集含有哪些base
        long long dp[1<<10]={0};
        //一开始，只有一个啥因数都不包含的空状态
        dp[0]=1;
        for(int i=2;i<=30;i++){
            //检查合法性
            if(!valid(i))continue;
            //转化为掩膜
            int mask=getmask(i);
            //背包转移，必须从后往前，想想为什么
            for(int state=(1<<10)-1;state;state--){
                //如果mask是state的子集，就可以转移
                if((state&mask)==mask){
                    // state-mask 的状态，配合任何一个数字i(也就是状态mask)，就能凑成一个state状态
                    dp[state]+=dp[state-mask]*cnt[i];
                    dp[state]%=MOD;
                }
            }
        }
        //最后特殊处理所有的数字1，这些1可取可不取，总共有2^cnt[1]种取法
        long long one=1;
        for(int i=0;i<cnt[1];i++)one=one*2%MOD;
        return accumulate(dp+1,dp+(1<<10),0ll)%MOD*one%MOD;

    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nums{4,2,3,15};
    auto ans=sol.numberOfGoodSubsets(nums);
    DBG(ans);

    system("pause");
    return 0;
}
