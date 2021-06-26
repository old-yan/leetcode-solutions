#include "SegTree.h"
#include "utils.h"

LazyTree<int,1> T(2000,[](int x,int y){return max(x,y);});
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vi old;
        int n=positions.size();
        for(auto&position:positions){
            old.pb(position[0]);
            old.pb(position[0]+position[1]-1);
        }
        vi rnk=getrank2(old);
        vi ans;
        T.set(0);
        REP(i,n){
            int left=rnk[i*2],right=rnk[i*2+1];
            int height=T(left,right)+positions[i][1];
            T.step(left,right,height);
            ans.pb(T.data[1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi positions=makevvi("[[4, 9], [8, 8], [6, 8], [8, 2]]");
    auto ans=sol.fallingSquares(positions);
    DBGV(ans);

    system("pause");
    return 0;
}
