#include "Union.h"
#include "utils.h"

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        Union u(26);
        for(auto&e:equations){
            if(e[1]=='='){
                u.unite(e[0]-'a',e[3]-'a');
            }
        }
        for(auto&e:equations){
            if(e[1]=='!'){
                if(u.same(e[0]-'a',e[3]-'a'))return false;
            }
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>equations{
        "a==b","b!=a"
    };
    auto ans=sol.equationsPossible(equations);
    DBG(ans);

    system("pause");
    return 0;
}
