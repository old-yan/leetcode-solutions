#include "utils.h"

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(ALL(intervals),[](vi&x,vi&y){
            if(x[0]!=y[0])return x[0]<y[0];
            else return x[1]>y[1];
        });
        int end=INT_MIN;
        int ans=0;
        for(auto&it:intervals){
            if(chmax(end,it[1]))ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi intervals=makevvi("[[1,4],[3,6],[2,8]]");
    auto ans=sol.removeCoveredIntervals(intervals);
    DBG(ans);

    system("pause");
    return 0;
}
