#include "utils.h"

class Solution {
    int bs(vi& v){
        int low = 0,high = v.size()-1;
        while (low<high){
            int mid = (high + low) / 2;
            if (v[mid]<v.back())high = mid;
            else low = mid+1;
        }
        return low;
    }
    int bs2(vi& v,int start,int end,int target){
        int low = start,high = end;
        while (low<high){
            int mid = (high + low) / 2;
            if (v[mid]>=target)high = mid;
            else low = mid+1;
        }
        if(v[low]==target)return low;
        else return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int start=bs(nums);
        if(target<=nums.back())return bs2(nums,start,nums.size()-1,target);
        else return bs2(nums,0,start-1,target);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4,5,6,7,0,1,2};
    auto ans=sol.search(nums,0);
    DBG(ans);

    system("pause");
    return 0;
}
