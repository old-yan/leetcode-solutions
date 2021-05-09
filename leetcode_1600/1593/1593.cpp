#include "utils.h"

class Solution {
    string s;
    set<string>S;
    int ans=1;
    void dfs(int cur){
        if(S.size()+s.size()-cur<=ans)return;
        if(cur==s.size())chmax(ans,int(S.size()));
        else{
            FOR(i,cur+1,s.size()+1){
                if(S.insert(s.substr(cur,i-cur)).second){
                    dfs(i);
                    S.erase(s.substr(cur,i-cur));
                }
            }
        }
    }
public:
    int maxUniqueSplit(string _s) {
        s=_s;
        dfs(0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="ababccc";
    auto ans=sol.maxUniqueSplit(s);
    DBG(ans);

    system("pause");
    return 0;
}
