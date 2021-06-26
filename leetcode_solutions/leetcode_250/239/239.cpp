#include "utils.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vi ans(nums.size()-k+1);
        deque<int>Q;
        REP(i,nums.size()){
            if(Q.front()==i-k)Q.pop_front();
            while(Q.size()&&nums[Q.back()]<nums[i])Q.pop_back();
            Q.pb(i);
            if(i>=k-1)ans[i-k+1]=nums[Q.front()];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,3,-1,-3,5,3,6,7};
    auto ans=sol.maxSlidingWindow(nums,3);
    DBGV(ans);

    system("pause");
    return 0;
}
