#include "utils.h"

class Solution {
    void toLower(char&c){
        c=tolower(c);
    }
    void toUpper(char&c){
        c=toupper(c);
    }
public:
    vector<string> letterCasePermutation(string S) {
        vi idxes;
        REP(i,S.size()){
            if(isalpha(S[i])){
                idxes.pb(i);
                toLower(S[i]);
            }
        }
        vector<string>ans(1<<idxes.size());
        REP(i,ans.size()){
            if(!i)ans[i]=S;
            else{
                int j=__builtin_ctz(i);
                ans[i]=ans[i-(1<<j)];
                toUpper(ans[i][idxes[j]]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="a1b2";
    auto ans=sol.letterCasePermutation(S);
    DBGV(ans);

    system("pause");
    return 0;
}
