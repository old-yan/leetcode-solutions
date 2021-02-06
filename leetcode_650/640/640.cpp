#include "utils.h"

class Solution {
    pair<int,int>fun(string&s){
        int a=0,b=0;
        int idx=1;
        while(idx<s.size()){
            int i;
            for(i=idx;s[i]&&s[i]!='+'&&s[i]!='-';i++);
        }
    }
public:
    string solveEquation(string equation) {
        int equal=equation.find_first_of('=');
        string left=equation.substr(0,equal);
        string right=equation.substr(equal+1);
        auto p1=fun(left);
        auto p2=fun(right);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string equation="x+5-3+x=6+x-2";
    auto ans=sol.solveEquation(equation);
    DBG(ans);

    system("pause");
    return 0;
}
