#include "utils.h"

class Solution {
    string expression;
    bool fun(int&idx){
        if(isalpha(expression[idx])){
            return expression[idx++]=='t';
        }
        else if(expression[idx]=='!'){
            idx+=2;
            auto res=fun(idx);
            idx++;
            return !res;
        }
        else{
            char c=expression[idx];
            idx+=2;
            vector<bool>v;
            while(true){
                v.pb(fun(idx));
                if(expression[idx++]!=',')break;
            }
            if(c=='&'){
                for(auto b:v)if(!b)return false;
                return true;
            }
            else{
                for(auto b:v)if(b)return true;
                return false;
            }
        }
    }
public:
    bool parseBoolExpr(string _expression) {
        expression=_expression;
        int idx=0;
        return fun(idx);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string expression="|(f,t)";
    auto ans=sol.parseBoolExpr(expression);
    DBG(ans);

    system("pause");
    return 0;
}
