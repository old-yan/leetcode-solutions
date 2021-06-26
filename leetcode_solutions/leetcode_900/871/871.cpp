#include "utils.h"

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        priority_queue<int>Q;
        int cur=startFuel;
        REP(i,n){
            while(Q.size()&&cur<stations[i][0]){
                cur+=Q.top();
                Q.pop();
            }
            if(cur<stations[i][0])return -1;
            Q.push(stations[i][1]);
        }
        while(Q.size()&&cur<target){
            cur+=Q.top();
            Q.pop();
        }
        if(cur<target)return -1;
        return n-Q.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int target=100;
    int startFuel=10;
    vvi stations=makevvi("[[10,60],[20,30],[30,30],[60,40]]");
    auto ans=sol.minRefuelStops(target,startFuel,stations);
    DBG(ans);

    system("pause");
    return 0;
}
