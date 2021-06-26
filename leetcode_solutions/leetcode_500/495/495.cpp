#include "utils.h"

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=;
        REP(i,timeSeries.size()){
            if(i+1<timeSeries.size()&&timeSeries[i+1]<timeSeries[i]+duration){
                ans+=timeSeries[i+1]-timeSeries[i];
            }
            else ans+=duration;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi timeSeries{1,4};
    int duration=2;
    auto ans=sol.findPoisonedDuration(timeSeries,duration);
    DBG(ans);

    system("pause");
    return 0;
}
