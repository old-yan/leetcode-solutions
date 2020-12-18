#include "utils.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>S;
        set<string>operators{"+","-","*","/"};
        for(string&s:tokens){
            if(operators.count(s)){
                int b=S.top();
                S.pop();
                int a=S.top();
                S.pop();
                if(s=="+")a+=b;
                if(s=="-")a-=b;
                if(s=="*")a*=b;
                if(s=="/")a/=b;
                S.push(a);
            }
            else S.push(s2i(s));
        }
        return S.top();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>tokens{"2", "1", "+", "3", "*"};
    auto ans=sol.evalRPN(tokens);
    DBG(ans);

    system("pause");
    return 0;
}
