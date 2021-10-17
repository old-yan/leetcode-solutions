#include "utils.h"

using ll=long long;
class Solution {
    int closest(vector<int>&v1,vector<int>&v2,ll half){
        ll best=INT_MIN;
        //双指针可以解决
        for(int i=0,j=v2.size()-1;i<v1.size()&&j>=0;){
            ll pair_sum=v1[i]+v2[j];
            if(abs(pair_sum-half)<abs(best-half))best=pair_sum;
            if(pair_sum>=half)j--;
            else i++;
        }
        return best;
    }
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size()/2;
        ll sum=accumulate(nums.begin(),nums.end(),0);
        ll half=sum/2;
        //front 表示 nums 的前一半，长度为 n
        vector<int>front(nums.begin(),nums.begin()+n);
        //使用 sum1 数组记录 front 的各种子序列的和
        int sum1[1<<n];
        memset(sum1,0,sizeof(sum1));
        for(int state=0;state<1<<n;state++){
            for(int i=0;i<n;i++){
                if(state>>i&1){
                    sum1[state]+=front[i];
                }
            }
        }
        //back 表示 nums 的后一半，长度为 n
        vector<int>back(nums.begin()+n,nums.end());
        //使用 sum2 数组记录 back 的各种子序列的和
        int sum2[1<<n];
        memset(sum2,0,sizeof(sum2));
        for(int state=0;state<1<<n;state++){
            for(int i=0;i<n;i++){
                if(state>>i&1){
                    sum2[state]+=back[i];
                }
            }
        }        
        //使用 sub1[len] 表示在 front 里取长度 len 的子序列，可能的和
        //使用 sub2[len] 表示在 back 里取长度 len 的子序列，可能的和
        vector<int>sub1[n+1],sub2[n+1];
        //将 sum1 和 sum2 的内容填到 sub1,sub2 数组里
        for(int state=0;state<1<<n;state++){
            int len=__builtin_popcount(state);
            sub1[len].push_back(sum1[state]);
            sub2[len].push_back(sum2[state]);
        }
        //将 sub1[len] 和 sub2[len] 全部排序
        for(int i=0;i<=n;i++){
            sort(sub1[i].begin(),sub1[i].end());
            sort(sub2[i].begin(),sub2[i].end());
        }
        ll ans=INT_MAX;
        //在 front 里取长度 i 的子序列，在 back 里取长度 n-i 的子序列，将它俩拼在一块，则它俩的和最好很靠近 half
        for(int i=0;i<=n;i++){
            //使用 closest 函数找出 sub1[i] 和 sub2[n-1] 里和最接近 half 的组合
            ll close=closest(sub1[i],sub2[n-i],half);
            //一半为 closest ，则另一半为 sum-closest
            ans=min(ans,abs(close-(sum-close)));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nums{2,-1,0,4,-2,-9};
    auto ans=sol.minimumDifference(nums);
    DBG(ans);

    system("pause");
    return 0;
}