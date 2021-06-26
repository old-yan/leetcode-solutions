#include "utils.h"

class Solution {
    int fun(string&s,int&idx){
        int signal=1;
        if(s[idx]=='+'||s[idx]=='-'){
            signal=s[idx++]=='+'?1:-1;
        }
        if(s[idx]=='('){
            int val=0;
            idx++;
            while(s[idx]!=')'){
                val+=fun(s,idx);
            }
            idx++;
            return signal*val;
        }
        else{
            int val=0;
            while(isdigit(s[idx])){
                val=val*10+(s[idx++]-'0');
            }
            return signal*val;
        }
    }
public:
    int calculate(string s) {
        int idx=0;
        string ss="(";
        for(char c:s)if(c!=' ')ss+=c;
        ss+=")";
        return fun(s,idx);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="(1+(4+5+2)-3)+(6+8)";
    auto ans=sol.calculate(s);
    DBG(ans);

    system("pause");
    return 0;
}
