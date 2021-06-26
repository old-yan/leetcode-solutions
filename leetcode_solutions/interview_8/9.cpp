#include "utils.h"

class Solution {
    vector<string>ans;
    char c[100],l=0;
    void dfs(int need,int left){
        if(!need){
            if(left){
                c[l++]=')';
                dfs(need,left-1);
                l--;
            }
            else ans.emplace_back(c,c+l);
        }
        else{
            if(left){
                c[l++]=')';
                dfs(need,left-1);
                l--;
            }
            c[l++]='(';
            dfs(need-1,left+1);
            l--;
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        dfs(n,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    auto ans=sol.generateParenthesis(n);
    DBGV(ans);

    system("pause");
    return 0;
}
