#include "utils.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(ALL(nums));
        priority_queue<pair<int,int>>Q;
        for(int i=0,j;i<nums.size();i=j){
            for(j=i+1;j<nums.size()&&nums[j]==nums[i];j++);
            Q.push(make_pair(j-i,nums[i]));
        }
        vi ans;
        while(k--){
            ans.pb(Q.top().second);
            Q.pop();
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,1,2,2,3};
    auto ans=sol.topKFrequent(nums,2);
    DBGV(ans);

    system("pause");
    return 0;
}
