#include "utils.h"

class Solution {
public:
    //将每一个元素替换为k之后，看前缀和中有多少个和的一半
    int waysToPartition(vector<int>& nums, int k) {
        int n=nums.size();
        //先求出最初始的前缀和
        ll presum[n+1];
        presum[0]=0;
        for(int i=0;i<n;i++)presum[i+1]=presum[i]+nums[i];
        //求出最初始的数组和
        ll total0=presum[n];
        //两个哈希表维护前半截和后半截中的前缀和的分布
        unordered_map<ll,int>M_left,M_right;
        //先把前缀和都填到第二个哈希表里
        for(int i=1;i<=n;i++)M_right[presum[i]]++;
        int ans=0;
        //求出不改数的情况下的答案(注意如果和为0，要减一，因为数组取全部也是自身的一半，但是不符合要求)
        if(total0%2==0){
            ans=total0?M_right[total0/2]:M_right[total0/2]-1;
        }
        //对每个数尝试进行修改
        for(int i=0;i<n;i++){
            //如果将 nums[i] 改为 k，发生的变化为 change
            ll change=k-nums[i];
            //数组和也会发生变化
            ll total=total0+change;
            if(total%2==0){
                //取出一半
                ll half=total/2;
                //在第一张哈希表里找能充当一半的位置
                int left=M_left[half];
                //在第二张哈希表里找能充当一半的位置
                int right=M_right[half-change];
                //拼起来就行了(还是注意数组和为0的情况)
                ans=max(ans,total?left+right:left+right-1);
            }
            //将当前位置前缀和从第二张表转移到第一张表，然后准备对下一个元素进行判断
            M_left[presum[i+1]]++;
            M_right[presum[i+1]]--;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14};
    int k=-33;
    auto ans=sol.waysToPartition(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}