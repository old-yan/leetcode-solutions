#include "utils.h"

class Solution {
    string s[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string digits;
    vector<string>ans;
    char path[10]={0};
    void dfs(int i){
        if(i==digits.size()){
            ans.pb(path);
        }
        else{
            for(char c:s[digits[i]-'0']){
                path[i]=c;
                dfs(i+1);
            }
        }
    }
public:
    vector<string> letterCombinations(string _digits) {
        if(_digits.empty())return ans;
        digits=_digits;
        dfs(0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string digits="23";
    auto ans=sol.letterCombinations(digits);
    DBGV(ans);

    system("pause");
    return 0;
}
