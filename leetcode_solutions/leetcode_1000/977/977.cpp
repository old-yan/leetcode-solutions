#include "utils.h"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]>=0){
            vi ans(n);
            REP(i,n)ans[i]=nums[i]*nums[i];
            return ans;
        }
        else if(nums.back()<=0){
            vi ans(n);
            REP(i,n)ans[n-1-i]=nums[i]*nums[i];
            return ans;
        }
        vi ans(n);
        int i,j,k;
        for(i=0,j=n-1,k=0;i<n;i++){
            if(nums[i]<0)ans[j--]=nums[i]*nums[i];
            else ans[k++]=nums[i]*nums[i];
        }
        inplace_merge(ans.begin(),ans.begin()+k,ans.end());
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-7,-3,2,3,11};
    auto ans=sol.sortedSquares(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
