#include "utils.h"

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        Union u(n);
        REP(i,n){
            REP(j,i){
                if(isConnected[i][j]){
                    u.unite(i,j);
                }
            }
        }
        return u.group;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi isConnected{
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    auto ans=sol.findCircleNum(isConnected);
    DBG(ans);

    system("pause");
    return 0;
}
