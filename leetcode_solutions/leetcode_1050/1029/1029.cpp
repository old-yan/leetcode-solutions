#include "utils.h"

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size()/2;
        int ans=0,more=0;
        REP(i,n*2)ans+=costs[i][0];
        priority_queue<int>Q;
        for(auto&co:costs){
            Q.push(co[1]-co[0]);
            more+=co[1]-co[0];
        }
        while(Q.size()>n){
            more-=Q.top();
            Q.pop();
        }
        return ans+more;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi costs=makevvi("[[10,20],[30,200],[400,50],[30,20]]");
    auto ans=sol.twoCitySchedCost(costs);
    DBG(ans);

    system("pause");
    return 0;
}
