#include "utils.h"

class Solution {
public:
    bool isValid(string s) {
        stack<string>S;
        for(char c:s){
            if(c=='a'){
                S.push("a");
            }
            else if(c=='b'){
                if(S.empty()||S.top()!="a")return false;
                S.pop();
                S.push("ab");
            }
            else{
                if(S.empty()||S.top()!="ab")return false;
                S.pop();
            }
        }
        return S.empty();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="aabcbc";
    auto ans=sol.isValid(s);
    DBG(ans);

    system("pause");
    return 0;
}
