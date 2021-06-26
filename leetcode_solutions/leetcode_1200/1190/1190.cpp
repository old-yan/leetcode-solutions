#include "utils.h"

class Solution {
    string s;
    string fun(int&idx){
        string res;
        while(s[idx]&&s[idx]!=')'){
            if(isalpha(s[idx])){
                res+=s[idx++];
            }
            else{
                auto tmp=fun(++idx);
                reverse(ALL(tmp));
                res+=tmp;
                idx++;
            }
        }
        return res;
    }
public:
    string reverseParentheses(string _s) {
        s=_s;
        int idx=0;
        return fun(idx);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="(u(love)i)";
    auto ans=sol.reverseParentheses(s);
    DBG(ans);

    system("pause");
    return 0;
}
