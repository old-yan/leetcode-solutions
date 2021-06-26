#include "utils.h"

class Solution {
    //group[i]中存放组号为i的那些个下标
    vector<int>group[2000];
public:
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            group[i%k].push_back(i);
        }
        #define N 1024
        //dp[i][j]表示令组号i之前(包括i)的组所变的元素的前缀异或和为j，所需的最小操作数
        int dp[k][N];
        for(int i=0;i<k;i++){
            //获取这个组的数字分布
            int cnt[N];
            memset(cnt,0,sizeof(cnt));
            for(int a:group[i])cnt[nums[a]]++;
            if(!i){
                for(int j=0;j<N;j++)dp[i][j]=group[i].size()-cnt[j];
            }
            else{
                int Min=*min_element(dp[i-1],dp[i]);
                //一种方案是将本组的都调动起来变化，从上一组dp[i-1]的最小值处转移到dp[i]的任何一处
                //由异或性质可知，必存在转移途径，操作数不超过group[i].size()
                fill(dp[i],dp[i+1],Min+group[i].size());
                //另一种方案就是可以
                for(int j=0;j<N;j++){
                    if(cnt[j]){
                        for(int pre=0;pre<N;pre++){
                            dp[i][pre^j]=min(dp[i][pre^j],int(dp[i-1][pre]+group[i].size()-cnt[j]));
                        }
                    }
                }
            }
        }
        return dp[k-1][0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,1,1,0,3};
    int k=3;
    auto ans=sol.minChanges(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
