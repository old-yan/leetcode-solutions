#include "utils.h"

class Solution {
    int fun(vi&nums,int l,int r,int k){
        if(l==r)return nums[l];
        int pivot=l+rand()%(r-l+1);
        int val=nums[pivot];
        swap(nums[l],nums[pivot]);
        int i1=l,i2=r;
        while(i1<i2){
            while(i1<i2&&nums[i2]>val)i2--;
            nums[i1]=nums[i2];
            while(i1<i2&&nums[i1]<=val)i1++;
            nums[i2]=nums[i1];
        }
        nums[i1]=val;
        if(k==i1-l+1)return val;
        if(k<i1-l+1){
            return fun(nums,l,i1-1,k);
        }
        else{
            return fun(nums,i1+1,r,k-i1+l-1);
        }
    }
public:
    int findKthLargest(vector<int>&nums,int k){
        // nth_element(&nums[0],&nums[0]+nums.size()-k,&nums[0]+nums.size());
        // return nums[nums.size()-k];
        return fun(nums,0,nums.size()-1,nums.size()-k+1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,2};
    int k=1;
    auto ans=sol.findKthLargest(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}