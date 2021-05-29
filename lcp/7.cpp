#include "utils.h"

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vi can[n];
        for(auto&r:relation){
            can[r[0]].pb(r[1]);
        }
        vi cur(n,0);
        cur[0]=1;
        REP(_,k){
            vi next(n,0);
            REP(i,n){
                for(int a:can[i]){
                    next[a]+=cur[i];
                }
            }
            cur.swap(next);
        }
        return cur[n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    vvi relations=makevvi("[[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]]");
    int k=3;
    auto ans=sol.numWays(n,relations,k);
    DBG(ans);

    system("pause");
    return 0;
}
