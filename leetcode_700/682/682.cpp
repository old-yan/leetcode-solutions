#include "utils.h"

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vi v;
        for(string&op:ops){
            if(isdigit(op.back())){
                v.pb(s2i(op));
            }
            else if(op=="+"){
                v.pb(v[v.size()-1]+v[v.size()-2]);
            }
            else if(op=="D"){
                v.pb(v.back()*2);
            }
            else v.pop_back();
        }
        return accumulate(ALL(v),0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>ops{"5","2","C","D","+"};
    auto ans=sol.calPoints(ops);
    DBG(ans);

    system("pause");
    return 0;
}
