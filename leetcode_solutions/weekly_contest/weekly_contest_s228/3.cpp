#include "utils.h"

class Solution {
public:
    //二分搜索
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(ALL(nums),greater<int>());
        int low=1,high=nums[0];
        while(low<high){
            //尝试将所有数字切割到mid或者mid以下，需要砍几刀
            int mid=(low+high)/2;
            int cnt=0;
            for(int a:nums){
                if(a>mid)cnt+=(a-1)/mid;
                else break;
            }
            //如果能在maxOperations刀前砍完，说明mid可能偏大，区间要下调；否则区间上调
            if(cnt<=maxOperations)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,4,8,2};
    int maxOperations=4;
    auto ans=sol.minimumSize(nums,maxOperations);
    DBG(ans);

    system("pause");
    return 0;
}
