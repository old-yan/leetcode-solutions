#include "utils.h"

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n=startTime.size();
        int ans=0;
        REP(i,n){
            if(startTime[i]<=queryTime&&queryTime<=endTime[i])ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi startTime{1,2,3};
    vi endTime{3,2,7};
    int queryTime=4;
    auto ans=sol.busyStudent(startTime,endTime,queryTime);
    DBG(ans);

    system("pause");
    return 0;
}
