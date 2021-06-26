#include "Trie.h"
#include "utils.h"

StaticTrie T;
class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        T.clear();
        vvi ans(smalls.size());
        REP(i,smalls.size())T.insert(smalls[i],i);
        REP(i,big.size()){
            int cur=0;
            FOR(j,i,big.size()){
                cur=T[cur][big[j]-'a'];
                if(!cur)break;
                if(T[cur][26]>=0)ans[T[cur][26]].pb(i);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string big="mississippi";
    vector<string>smalls{
        "is","ppi","hi","sis","i","ssippi"
    };
    auto ans=sol.multiSearch(big,smalls);
    DBGVV(ans);

    system("pause");
    return 0;
}
