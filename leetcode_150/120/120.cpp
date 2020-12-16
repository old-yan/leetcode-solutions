#include "utils.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vi dis{triangle[0][0]};
        FOR(i,1,triangle.size()){
            vi newdis(i+1,INT_MAX);
            REP(j,triangle[i-1].size()){
                chmin(newdis[j],dis[j]+triangle[i][j]);
                chmin(newdis[j+1],dis[j]+triangle[i][j+1]);
            }
            dis=newdis;
        }
        return *min_element(ALL(dis));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi triangle{
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    auto ans=sol.minimumTotal(triangle);
    DBG(ans);

    system("pause");
    return 0;
}
