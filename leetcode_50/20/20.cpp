#include "utils.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char>S;
        map<char,char>M={
            {')','('},{']','['},{'}','{'}
        };
        for(char c:s){
            if(M.count(c)){
                if(S.empty()||S.top()!=M[c])return false;
                S.pop();
            }
            else S.push(c);
        }
        return S.empty();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="()[]{}";
    auto ans=sol.isValid(s);
    DBG(ans);

    system("pause");
    return 0;
}
