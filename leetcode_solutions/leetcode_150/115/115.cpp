#include "utils.h"

class Solution {
    #define X 10
    int dp[X+1][X+1];
    string s,t;
    int fun(int i,int j){
        if(dp[i][j]>=0)return dp[i][j];
        if(j==0)return dp[i][j]=1;
        if(i==0)return dp[i][j]=0;
        dp[i][j]=fun(i-1,j);
        if(s[i-1]==t[j-1])dp[i][j]+=fun(i-1,j-1);
        return dp[i][j];
    }
public:
    int numDistinct(string _s, string _t) {
        memset(dp,0xff,sizeof(dp));
        s=_s,t=_t;
        return fun(s.size(),t.size());
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="rabbbit";
    string t="rabbit";
    auto ans=sol.numDistinct(s,t);
    DBG(ans);

    system("pause");
    return 0;
}
