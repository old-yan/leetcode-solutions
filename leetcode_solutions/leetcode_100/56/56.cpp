#include "utils.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(ALL(intervals));
        vvi ans;
        REP(i,intervals.size()){
            if(ans.size()&&intervals[i][0]<=ans.back()[1]){
                chmax(ans.back()[1],intervals[i][1]);
            }
            else ans.pb(intervals[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi intervals{
        {1,3},{2,6},{8,10},{15,18}
    };
    auto ans=sol.merge(intervals);
    DBGVV(ans);

    system("pause");
    return 0;
}
