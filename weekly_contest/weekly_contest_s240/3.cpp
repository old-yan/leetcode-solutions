#include "utils.h"

class Solution {
    int n;
    vi leftSmaller,rightSmaller;
    void getBorder(vi&nums){
        //单调栈获取左右边界，也就是离自己最近的、比自己大的值
        //leftBigger和rightSmaller的默认值是需要填的，因为即使没有比自己大的，遇到数组边界也需要停下来
        leftSmaller.resize(n,-1);
        rightSmaller.resize(n,n);
        stack<int>S;
        REP(i,n){
            while(S.size()&&nums[S.top()]>=nums[i])S.pop();
            if(S.size())leftSmaller[i]=S.top();
            S.push(i);            
        }
        stack<int>().swap(S);
        REPR(i,n-1){
            while(S.size()&&nums[S.top()]>=nums[i])S.pop();
            if(S.size())rightSmaller[i]=S.top();
            S.push(i);
        }
    }
public:
    //本题需枚举每个位置的值作为最小值
    //那么相应的，需要知道以其作为最小值的区间最宽能有多宽
    int maxSumMinProduct(vector<int>& nums) {
        n=nums.size();
        //先获取边界
        getBorder(nums);
        //求个前缀和数组，方便差分取子数组和
        ll _presum[n+1];
        auto presum=_presum+1;
        presum[-1]=0;
        REP(i,n)presum[i]=presum[i-1]+nums[i];
        //遍历找答案
        ll ans=0;
        REP(i,n){
            chmax(ans,nums[i]*(presum[rightSmaller[i]-1]-presum[leftSmaller[i]]));
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi v{1,2,3,2};
    auto ans=sol.maxSumMinProduct(v);
    DBG(ans);

    system("pause");
    return 0;
}
