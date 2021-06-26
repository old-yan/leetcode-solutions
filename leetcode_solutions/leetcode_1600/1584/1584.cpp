#include "Union.h"
#include "utils.h"

class Solution {
    int getdis(vi&v1,vi&v2){
        return abs(v1[0]-v2[0])+abs(v1[1]-v2[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        Union u(n);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>Q;
        REP(i,n)REP(j,i){
            Q.emplace(getdis(points[i],points[j]),i,j);
        }
        int ans=0;
        while(u.group>1){
            auto [dis,i,j]=Q.top();
            Q.pop();
            if(u.unite(i,j))ans+=dis;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[0,0],[2,2],[3,10],[5,2],[7,0]]");
    auto ans=sol.minCostConnectPoints(points);
    DBG(ans);

    system("pause");
    return 0;
}
