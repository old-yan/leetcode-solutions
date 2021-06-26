#include "utils.h"

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MIN;
        deque<pair<int,int>>Q;
        REPR(i,n-1){
            if(Q.front().first>i+k)Q.pop_front();
            int cur=nums[i]+max(Q.front().second,0);
            chmax(ans,cur);
            while(Q.size()&&Q.back().second<=cur)Q.pop_back();
            Q.emplace_back(i,cur);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{10,2,-10,5,20};
    int k=2;
    auto ans=sol.constrainedSubsetSum(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
