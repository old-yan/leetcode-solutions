#include "Union.h"
#include "utils.h"

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        Union u(accounts.size());
        unordered_map<string,int>M;
        REP(i,accounts.size()){
            FOR(j,1,accounts[i].size()){
                if(!M.count(accounts[i][j]))M[accounts[i][j]]=i;
                else u.unite(i,M[accounts[i][j]]);
            }
        }
        int getid[accounts.size()];
        vector<vector<string>>ans;
        REP(i,accounts.size()){
            int id;
            if(i==u.Find(i)){
                id=ans.size();
                getid[i]=id;
                ans.pb(vector<string>{accounts[i][0]});
            }
            else id=getid[u.Find(i)];
            FOR(j,1,accounts[i].size()){
                if(M.erase(accounts[i][j])){
                    ans[id].pb(accounts[i][j]);
                }
            }
        }
        for(auto&v:ans){
            sort(v.begin()+1,v.end());
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<string>>accounts{
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };
    auto ans=sol.accountsMerge(accounts);
    DBGVV(ans);

    system("pause");
    return 0;
}
