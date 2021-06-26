#include "utils.h"

class Solution {
    int n,dp[10];
    string dfs(int curidx,int currnk,char ban){
        if(curidx==n)return "";
        else{
            for(char ch:{'a','b','c'}){
                if(ch==ban)continue;
                if(currnk<=dp[curidx])return ch+dfs(curidx+1,currnk,ch);
                else currnk-=dp[curidx];
            }
        }
    }
public:
    string getHappyString(int _n, int k) {
        n=_n;
        dp[n-1]=1;
        REPR(i,n-2)dp[i]=dp[i+1]*2;
        if(dp[0]*3<k)return "";
        else return dfs(0,k,'d');
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=1;
    int k=3;
    auto ans=sol.getHappyString(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
