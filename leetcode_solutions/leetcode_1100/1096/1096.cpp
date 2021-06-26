#include "utils.h"

class Solution {
    string expression;
    vector<string>parse(int&idx){
        vector<string>res{""};
        for(;expression[idx]=='{'||isalpha(expression[idx]);++idx){
            if(expression[idx]=='{'){
                vector<string>tmp;
                do{
                    for(auto&s:parse(++idx))tmp.pb(s);
                }while(expression[idx]==',');
                vector<string>tmp2;
                for(string&a:res)for(string&b:tmp)tmp2.pb(a+b);
                sort(ALL(tmp2));
                tmp2.resize(unique(ALL(tmp2))-tmp2.begin());
                res.swap(tmp2);
            }
            else{
                for(string&s:res)s+=expression[idx];
                sort(ALL(res));
            }
        }
        return res;
    }
public:
    vector<string> braceExpansionII(string _expression) {
        expression=_expression;
        int idx=0;
        return parse(idx);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string expression="{a,b}{c,{d,e}}";
    auto ans=sol.braceExpansionII(expression);
    DBGV(ans);

    system("pause");
    return 0;
}
