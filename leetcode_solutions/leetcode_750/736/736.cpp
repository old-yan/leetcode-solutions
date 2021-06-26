#include "utils.h"

class Solution {
    unordered_map<string,stack<int>>M;
    int fun(string&expression,int&idx){
        if(expression[idx]!='('){
            if(isalpha(expression[idx])){
                int end=min(expression.find_first_of(' ',idx),expression.find_first_of(')',idx));
                int val=M[expression.substr(idx,end-idx)].top();
                idx=end;
                return val;
            }
            else{
                int end=min(expression.find_first_of(' ',idx),expression.find_first_of(')',idx));
                int val=s2i(expression.substr(idx,end-idx));
                idx=end;
                return val;
            }
        }
        else if(expression[++idx]=='l'){
            unordered_set<string>S;
            idx+=4;
            while(isalpha(expression[idx])){
                int end=min(expression.find_first_of(' ',idx),expression.find_first_of(')',idx));
                string s=expression.substr(idx,end-idx);
                if(expression[end]==')'){
                    int val=M[s].top();
                    for(auto&it:S)M[it].pop();
                    idx=end+1;
                    return val;
                }
                else{
                    idx=end+1;
                    int val=fun(expression,idx);
                    if(!S.insert(s).second)M[s].pop();
                    M[s].push(val);
                    idx++;
                }
            }
            int val=fun(expression,idx);
            for(auto&it:S)M[it].pop();
            idx++;
            return val;
        }
        else if(expression[idx]=='a'){
            idx+=4;
            int a=fun(expression,idx);
            idx++;
            int b=fun(expression,idx);
            idx++;
            return a+b;
        }
        else{
            idx+=5;
            int a=fun(expression,idx);
            idx++;
            int b=fun(expression,idx);
            idx++;
            return a*b;
        }
    }
public:
    int evaluate(string expression) {
        int idx=0;
        return fun(expression,idx);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string expression="(let x 2 (mult x (let x 3 y 4 (add x y))))";
    auto ans=sol.evaluate(expression);
    DBG(ans);

    system("pause");
    return 0;
}
