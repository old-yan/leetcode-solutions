#include "utils.h"

class Solution {
public:
    bool checkPartitioning(string s) {
        auto arm=getarm(s);
        FOR(left,1,s.size()-1){
            if(!query_polindromic(arm,0,left-1))continue;
            FOR(right,left,s.size()-1){
                if(query_polindromic(arm,left,right)&&query_polindromic(arm,right+1,s.size()-1)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abcbdd";
    auto ans=sol.checkPartitioning(s);
    DBG(ans);

    system("pause");
    return 0;
}
