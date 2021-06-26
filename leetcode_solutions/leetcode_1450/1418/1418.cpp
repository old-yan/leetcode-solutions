#include "utils.h"

class Solution {
    vector<string>v;
    int M[501][500]={0};
    void init(vector<vector<string>>& orders){
        for(auto&s:orders)v.pb(s[2]);
        sort(ALL(v));
        v.resize(unique(ALL(v))-v.begin());
    }
    int find(string&s){
        return lower_bound(ALL(v),s)-v.begin();
    }
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        init(orders);
        bitset<501>appear;
        for(auto&s:orders){
            M[s2i(s[1])][find(s[2])]++;
            appear.set(s2i(s[1]));
        }
        vector<vector<string>>ans;
        vector<string>menu{"Table"};
        menu.insert(menu.end(),ALL(v));
        ans.pb(menu);
        FOR(i,1,501)if(appear[i]){
            vector<string>res{i2s(i)};
            REP(j,v.size()){
                res.pb(i2s(M[i][j]));
            }
            ans.pb(res);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<string>>orders{
        {"David","3","Ceviche"},
        {"Corina","10","Beef Burrito"},
        {"David","3","Fried Chicken"},
        {"Carla","5","Water"},
        {"Carla","5","Ceviche"},
        {"Rous","3","Ceviche"}
    };
    auto ans=sol.displayTable(orders);
    DBGVV(ans);

    system("pause");
    return 0;
}
