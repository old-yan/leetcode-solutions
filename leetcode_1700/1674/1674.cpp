#include "utils.h"

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int a[limit*2+2];
        memset(a,0,sizeof(a));
        int n=nums.size();
        REP(i,n/2){
            int Min=min(nums[i],nums[n-1-i])+1;
            int Max=max(nums[i],nums[n-1-i])+limit;
            a[Min]++;
            a[Max+1]--;
            a[nums[i]+nums[n-1-i]]++;
            a[nums[i]+nums[n-1-i]+1]--;
        }
        partial_sum(a,a+limit*2+1,a);
        return n-*max_element(a,a+limit*2+1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,4,3};
    int limit=4;
    auto ans=sol.minMoves(nums,limit);
    DBG(ans);

    system("pause");
    return 0;
}
