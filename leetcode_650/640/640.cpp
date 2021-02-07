#include "utils.h"

class Solution {
    pair<int,int>fun(string&s){
        int a=0,b=0;
        int idx=0;
        while(idx<s.size()){
            int i;
            for(i=idx+1;s[i]&&s[i]!='+'&&s[i]!='-';i++);
            if(s[i-1]=='x'){
                if(i>1&&isdigit(s[i-2])){
                    if(s[idx]=='+')a+=s2i(s.substr(idx+1,i-idx-2));
                    else a+=s2i(s.substr(idx,i-idx-1));
                }
                else if(s[idx]=='-')a--;
                else a++;
            }
            else{
                if(s[idx]=='+')b+=s2i(s.substr(idx+1,i-idx-1));
                else b+=s2i(s.substr(idx,i-idx));
            }
            idx=i;
        }
        return {a,b};
    }
public:
    string solveEquation(string equation) {
        int equal=equation.find_first_of('=');
        string left=equation.substr(0,equal);
        string right=equation.substr(equal+1);
        auto p1=fun(left);
        auto p2=fun(right);
        if(p1.first==p2.first){
            if(p1.second!=p2.second)return "No solution";
            else return "Infinite solutions";
        }
        else{
            return "x="+i2s((p2.second-p1.second)/(p1.first-p2.first));
        }
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
