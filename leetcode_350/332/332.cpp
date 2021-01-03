#include "utils.h"

class Solution {
    set<string>S;
    unordered_map<string,int>M;
    vector<string>V;
    vector<multiset<int>>p;
    vector<string>ans;
    void dfs(int cur){
        while(p[cur].size()){
            int next=*p[cur].begin();
            p[cur].erase(p[cur].begin());
            dfs(next);
        }
        ans.pb(V[cur]);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto&A:tickets){
            S.insert(A[0]);
            S.insert(A[1]);
        }
        int i=0;
        for(auto&a:S){
            V.pb(a);
            M[a]=i++;
        }
        p.resize(S.size());
        for(auto&A:tickets){
            int i=M[A[0]],j=M[A[1]];
            p[i].insert(j);
        }
        dfs(M["JFK"]);
        reverse(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<string>>tickets{
        {"MUC","LHR"},
        {"JFK","MUC"},
        {"SFO","SJC"},
        {"LHR","SFO"}
    };
    auto ans=sol.findItinerary(tickets);
    DBGV(ans);

    system("pause");
    return 0;
}
