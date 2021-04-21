#include "utils.h"

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        FOR(i,2,coordinates.size()){
            int dir=getDirection(&coordinates[0][0],&coordinates[1][0],&coordinates[i][0]);
            if(dir%2==0)return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi coordinates=makevvi("[[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]");
    auto ans=sol.checkStraightLine(coordinates);
    DBG(ans);

    system("pause");
    return 0;
}
