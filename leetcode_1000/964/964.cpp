#include "utils.h"

class Solution {
    int ans=INT_MAX,cost[30],x;
    void dfs(ll rest,int curidx,ll unit,int curdis){
        if(!rest)chmin(ans,curdis);
        else if(curdis<ans){
            dfs(rest%unit,curidx-1,unit/x,curdis+(rest/unit)*cost[curidx]);
            dfs(unit-rest%unit,curidx-1,unit/x,curdis+(rest/unit+1)*cost[curidx]);
        }
    }
public:
    int leastOpsExpressTarget(int _x, int target) {
        REP(i,30)cost[i]=i?i:2;
        x=_x;
        ll unit=x,i=1;
        while(unit<target){
            unit*=x;
            i++;
        }
        dfs(target,i,unit,0);
        return ans-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int x=3;
    int target=5;
    auto ans=sol.leastOpsExpressTarget(x,target);
    DBG(ans);

    system("pause");
    return 0;
}
