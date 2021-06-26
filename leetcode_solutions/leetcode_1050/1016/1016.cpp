#include "utils.h"

class Solution {
public:
    bool queryString(string S, int N) {
        bitset<10000>appear;
        REP(i,S.size()){
            int cur=0;
            FOR(j,i,i+10){
                if(j>=S.size())break;
                cur=cur*2+S[j]-'0';
                appear.set(cur);
            }
        }
        FOR(i,1,N+1){
            if(!appear[i])return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="0110";
    int N=3;
    auto ans=sol.queryString(S,N);
    DBG(ans);

    system("pause");
    return 0;
}
