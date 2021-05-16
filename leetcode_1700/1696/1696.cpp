#include "utils.h"

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        deque<pair<int,int>>Q;
        for(int i=0;i<n;i++){
            while(Q.size()&&Q.front().first<i-k)Q.pop_front();
            int j=Q.size()?Q.front().second+nums[i]:nums[i];
            while(Q.size()&&Q.back().second<=j)Q.pop_back();
            Q.emplace_back(i,j);
        }
        return Q.back().second;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,-1,-2,4,-7,3};
    int k=2;
    auto ans=sol.maxResult(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
