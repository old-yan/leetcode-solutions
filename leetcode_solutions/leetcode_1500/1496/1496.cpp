#include "utils.h"

class Solution {
    int rnk[128];
    void init(){
        string s="NWSE";
        REP(i,s.size()){
            rnk[s[i]]=i;
        }
    }
public:
    bool isPathCrossing(string path) {
        init();
        int x=0,y=0;
        set<pair<int,int>>S({{0,0}});
        for(char c:path){
            x+=di[rnk[c]];
            y+=dj[rnk[c]];
            if(!S.emplace(x,y).second)return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string path="NES";
    auto ans=sol.isPathCrossing(path);
    DBG(ans);

    system("pause");
    return 0;
}
