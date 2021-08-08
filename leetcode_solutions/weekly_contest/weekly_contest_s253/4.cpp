#include "utils.h"

class Solution {
public:
    //和最长上升子序列问题是一样的问题，但是是最长不下降子序列问题，所以用upper_bound不是lower_bound
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vi end_of_lis(obstacles.size(),INT_MAX);
        vi ans;
        for(int a:obstacles){
            int i=upper_bound(ALL(end_of_lis),a)-end_of_lis.begin();
            ans.push_back(i+1);
            end_of_lis[i]=a;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi obstacles{3,1,5,6,4,2};
    auto ans=sol.longestObstacleCourseAtEachPosition(obstacles);
    DBGV(ans);

    system("pause");
    return 0;
}
