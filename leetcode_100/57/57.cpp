#include "utils.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int idx=0;
        vvi ans;
        while(idx<intervals.size()&&intervals[idx][1]<newInterval[0])ans.pb(intervals[idx++]);
        while(idx<intervals.size()&&intervals[idx][0]<=newInterval[1]){
            chmin(newInterval[0],intervals[idx][0]);
            chmax(newInterval[1],intervals[idx++][1]);
        }
        ans.pb(newInterval);
        while(idx<intervals.size())ans.pb(intervals[idx++]);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi intervals{
        {1,2},{3,5},{6,7},{8,10},{12,16}
    };
    vi newInterval{4,8};
    auto ans=sol.insert(intervals,newInterval);
    DBGVV(ans);

    system("pause");
    return 0;
}
