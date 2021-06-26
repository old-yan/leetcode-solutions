#include "utils.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size(),ans=INT_MAX,sum=accumulate(ALL(nums),0);
        if(sum<x)return -1;
        for(int i=0,j=0,k=sum;i<n;k+=nums[i++]){
            while(k>x&&j<n){
                k-=nums[j++];
            }
            if(k>x)break;
            if(k==x)chmin(ans,i+n-j);
        }
        return ans==INT_MAX?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,4,2,3};
    int x=5;
    auto ans=sol.minOperations(nums,x);
    DBG(ans);

    system("pause");
    return 0;
}
