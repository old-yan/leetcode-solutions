#include "SegTree.h"
#include "utils.h"

class Solution {
    int fun(vi&nums,int val){
        int ans=0;
        for(int i=0,j=0,k=0;j<nums.size();j++){
            while(nums[i]<nums[j]-val)i++;
            while(k<nums.size()&&nums[k]<=nums[j]+val)k++;
            ans+=k-i-1;
        }
        return ans;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(ALL(nums));
        int low=0,high=nums.back()-nums.front();
        while(low<high){
            int mid=(low+high)/2;
            if(fun(nums,mid)>=k*2)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,3,1};
    int k=1;
    auto ans=sol.smallestDistancePair(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
