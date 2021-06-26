#include "utils.h"

class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int dx=0,dy=0;
        map<pair<int,int>,int>M;
        REP(i,command.size()){
            M[{dx,dy}]=i;
            if(command[i]=='U')dy++;
            else dx++;
        }
        int a=min(x/dx,y/dy);
        if(!M.count({x-a*dx,y-a*dy}))return false;
        int b=M[{x-a*dx,y-a*dy}];
        for(auto&o:obstacles){
            int ai=min(o[0]/dx,o[1]/dy);
            if(M.count({o[0]-ai*dx,o[1]-ai*dy})){
                int bi=M[{o[0]-ai*dx,o[1]-ai*dy}];
                if(tie(a,b)>=tie(ai,bi))return false;
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string command="URR";
    vvi obstacles=makevvi("[]");
    int x=3;
    int y=2;
    auto ans=sol.robot(command,obstacles,x,y);
    DBG(ans);

    system("pause");
    return 0;
}
