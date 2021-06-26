#include "Union.h"
#include "utils.h"

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        Union u(n);
        REP(i,n){
            REP(j,i){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]){
                    u.unite(i,j);
                }
            }
        }
        return n-u.group;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi stones=makevvi("[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]");
    auto ans=sol.removeStones(stones);
    DBG(ans);

    system("pause");
    return 0;
}
