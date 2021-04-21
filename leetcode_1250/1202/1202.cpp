#include "Union.h"
#include "utils.h"

Union u(100000);
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        u.n=s.size();
        u.reset();
        for(auto&p:pairs){
            u.unite(p[0],p[1]);
        }
        unordered_map<int,vi>M;
        REP(i,s.size()){
            M[u.Find(i)].pb(i);
        }
        for(auto&it:M){
            string ss;
            for(int a:it.second)ss.pb(s[a]);
            sort(ALL(ss));
            sort(ALL(it.second));
            REP(i,it.second.size()){
                s[it.second[i]]=ss[i];
            }
        }
        return s;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="dcab";
    vvi pairs=makevvi("[[0,3],[1,2]]");
    auto ans=sol.smallestStringWithSwaps(s,pairs);
    DBG(ans);

    system("pause");
    return 0;
}
