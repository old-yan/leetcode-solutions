#include "utils.h"

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vi v;
        for(auto&s:timePoints){
            int hour,minute;
            hour=s2i(s.substr(0,2));
            minute=s2i(s.substr(3,2));
            v.pb(hour*60+minute);
            v.pb(hour*60+minute+1440);
        }
        sort(ALL(v));
        int ans=INT_MAX;
        REP(i,v.size()-1){
            chmin(ans,v[i+1]-v[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>timePoints{
        "00:00","23:59","00:00"
    };
    auto ans=sol.findMinDifference(timePoints);
    DBG(ans);

    system("pause");
    return 0;
}
