#include "utils.h"

class Solution {
    int need[100][100]={0};
    int dp[100][100];
public:
    int palindromePartition(string s, int k) {
        int n=s.size();
        REP(i,n){
            FOR(j,i,n){
                for(int l=i,r=j;l<r;l++,r--)need[i][j]+=s[l]!=s[r];
            }
        }
        REP(i,n){
            dp[i][0]=need[0][i];
            FOR(j,1,k){
                dp[i][j]=0x3f3f3f3f;
                FOR(l,max(0,int(j)-2),i){
                    chmin(dp[i][j],dp[l][j-1]+need[l+1][i]);
                }
            }
        }
        return dp[n-1][k-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="leetcode";
    int k=8;
    auto ans=sol.palindromePartition(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
