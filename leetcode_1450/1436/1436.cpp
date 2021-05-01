#include "utils.h"

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string>S;
        for(auto&p:paths){
            S.emplace(p[1]);
        }
        for(auto&p:paths){
            S.erase(p[0]);
        }
        return *S.begin();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<string>>paths{
        {"London","New York"},
        {"New York","Lima"},
        {"Lima","Sao Paulo"}
    };
    auto ans=sol.destCity(paths);
    DBG(ans);

    system("pause");
    return 0;
}
