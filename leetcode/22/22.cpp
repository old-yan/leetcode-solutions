#include "utils.h"

class Solution {
    int n;
    char c[1000]={0};
    vector<string>ans;
    void dfs(int i,int l,int r){
        if(l<n){
            c[i]='(';
            dfs(i+1,l+1,r);
        }
        if(l>r){
            c[i]=')';
            dfs(i+1,l,r+1);
        }
        if(i==n*2)ans.pb(c);
    }
public:
    vector<string> generateParenthesis(int _n) {
        n=_n;
        dfs(0,0,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    auto ans=sol.generateParenthesis(n);
    DBGV(ans);

    system("pause");
    return 0;
}
