#include "utils.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<int,int>>Q;
        vi ans;
        for(int left=0,right=0;right<n;right++){
            while(Q.front().first<=right-k)Q.pop_front();
            while(Q.back().second<=nums[right])Q.pop_back();
            Q.emplace_back(right,nums[right]);
            if(right>=k-1)ans.pb(Q.front().second);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,3,-1,-3,5,3,6,7};
    int k=3;
    auto ans=sol.maxSlidingWindow(nums,k);
    DBGV(ans);

    system("pause");
    return 0;
}
