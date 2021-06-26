#include "utils.h"

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.pb({1,0});
        restrictions.pb({n,n-1});
        sort(ALL(restrictions));
        REP(i,restrictions.size()-1){
            chmin(restrictions[i+1][1],restrictions[i][1]+restrictions[i+1][0]-restrictions[i][0]);
        }
        FORR(i,restrictions.size()-1,1){
            chmin(restrictions[i-1][1],restrictions[i][1]+restrictions[i][0]-restrictions[i-1][0]);
        }
        int ans=0;
        FOR(i,1,restrictions.size()){
            int d=restrictions[i][0]-restrictions[i-1][0];
            int h1=restrictions[i-1][1],h2=restrictions[i][1];
            chmax(ans,(h1+h2+d)/2);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    vvi restrictions=makevvi("[[2,1],[4,1]]");
    auto ans=sol.maxBuilding(n,restrictions);
    DBG(ans);

    system("pause");
    return 0;
}
