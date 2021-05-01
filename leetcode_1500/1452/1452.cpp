#include "utils.h"

class Solution {
    unordered_map<string,int>idmap;
    int getid(string&s){
        if(idmap.count(s))return idmap[s];
        else return idmap[s]=idmap.size();
    }
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n=favoriteCompanies.size();
        bitset<50000>b[n];
        REP(i,favoriteCompanies.size())for(string&s:favoriteCompanies[i]){
            b[i].set(getid(s));
        }
        vi ans;
        REP(i,n){
            bool flag=false;
            REP(j,n)if(j!=i){
                if((b[i]&b[j]).count()==b[i].count()){
                    flag=true;
                    break;
                }
            }
            if(!flag)ans.pb(i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<string>>favoriteCompanies{
        {"leetcode","google","facebook"},
        {"google","microsoft"},
        {"google","facebook"},
        {"google"},
        {"amazon"}
    };
    auto ans=sol.peopleIndexes(favoriteCompanies);
    DBGV(ans);

    system("pause");
    return 0;
}
