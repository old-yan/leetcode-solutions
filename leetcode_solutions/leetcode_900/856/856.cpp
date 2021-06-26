#include "utils.h"

class Solution {
    int ans=0;
    void fun(string&S,int&idx,int multiple){
        if(S[++idx]==')'){
            ans+=multiple;
        }
        else{
            while(S[idx]!=')'){
                fun(S,idx,multiple<<1);
            }
        }
        idx++;
    }
public:
    int scoreOfParentheses(string S) {
        int idx=0;
        while(idx<S.size()){
            fun(S,idx,1);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="(()(()))";
    auto ans=sol.scoreOfParentheses(S);
    DBG(ans);

    system("pause");
    return 0;
}
