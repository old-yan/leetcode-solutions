#include "utils.h"

int _dp[500001][6];
auto dp=_dp+1;

class Solution {
    int rnk[128];
    void init(){
        rnk['a']=1;
        rnk['e']=2;
        rnk['i']=3;
        rnk['o']=4;
        rnk['u']=5;
        fill(dp[-1],dp[0],INT_MIN);
        dp[-1][0]=0;
    }
public:
    //本题显然可以动态规划
    //rnk数组表示每种字符的排名，'aeiou'分别对应12345
    //dp[i][j]表示到下标i处，以j结尾的子字符串有多长（特别的,dp[i][0]表示空字符串）
    //那么dp[i][1~5]就可能从dp[i-1][0~5]转移而来
    int longestBeautifulSubstring(string word) {
        init();
        int n=word.size();
        int ans=0;
        REP(i,n){
            char c=rnk[word[i]];
            dp[i][0]=0;
            FOR(j,1,6){
                if(j==c)dp[i][j]=max(dp[i-1][j-1]+1,dp[i-1][j]+1);
                else dp[i][j]=INT_MIN;
            }
            chmax(ans,dp[i][5]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word="uu";
    auto ans=sol.longestBeautifulSubstring(word);
    DBG(ans);

    system("pause");
    return 0;
}
