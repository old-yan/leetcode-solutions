#include "utils.h"

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        ll sum[candiesCount.size()+1];
        sum[0]=0;
        REP(i,candiesCount.size()){
            sum[i+1]=sum[i]+candiesCount[i];
        }
        vector<bool>ans;
        for(auto&q:queries){
            ll type=q[0],day=q[1],cap=q[2];
            ll before=sum[type];
            ll early=before/cap;
            ll late=sum[type+1]-1;
            ans.pb(day>=early&&day<=late);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi candiesCount{7,4,5,3,8};
    vvi queries=makevvi("[[0,2,2],[4,2,4],[2,13,1000000000]]");
    auto ans=sol.canEat(candiesCount,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
