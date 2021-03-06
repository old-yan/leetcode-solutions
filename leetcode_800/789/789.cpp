#include "utils.h"

class Solution {
    int getDis(vi&pos1,vi&pos2){
        return abs(pos2[0]-pos1[0])+abs(pos2[1]-pos1[1]);
    }
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vi cur={0,0};
        int dis=getDis(cur,target);
        for(auto&ghost:ghosts){
            if(getDis(ghost,target)<=dis)return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi ghosts=makevvi("[[1,0],[0,3]]");
    vi targets{0,1};
    auto ans=sol.escapeGhosts(ghosts,targets);
    DBG(ans);

    system("pause");
    return 0;
}
