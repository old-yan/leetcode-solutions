#include "utils.h"

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int minCeiling=INT_MAX;
        for(auto&A:nums){
            chmin(minCeiling,A.back());
        }
        auto comp=[](vi::iterator x,vi::iterator y)->bool{
            return *x>*y;
        };
        priority_queue<vi::iterator,vector<vi::iterator>,decltype(comp)>Q(comp);
        int Max=INT_MIN;
        for(auto&A:nums){
            chmax(Max,A[0]);
            Q.push(A.begin());
        }
        vi ans{*Q.top(),Max};
        int mind=ans[1]-ans[0];
        while(*Q.top()<minCeiling){
            auto it=next(Q.top());
            chmax(Max,*it);
            Q.pop();
            Q.push(it);
            if(chmin(mind,Max-*Q.top())){
                ans={*Q.top(),Max};
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi nums{
        {4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}
    };
    auto ans=sol.smallestRange(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
