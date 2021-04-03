#include "utils.h"

class Solution {
    bool dp[1000][1000]={0};//dp[i][j]表示只看左边，target[i]可以和stamp[j]对齐
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m=stamp.size(),n=target.size();
        //dp[i][j]取决于 dp[i-1][m-1]
        //或者target[i-j~i]=stamp[0~j],换言之 dp[i-j][0] -->dp[i][j]
        REP(i,n){
            bool can=false;
            if(i+m<=n&&stamp[0]==target[i])can=dp[i][0]=true;
            FOR(j,1,m){
                if(target[i]!=stamp[j])continue;
                dp[i][j]=(j<=i&&j>=i+m-n&&(!i||dp[i-1][m-1]))||(i&&dp[i-1][j-1]);
                can=can||dp[i][j];
            }
            if(!can)return {};
        }
        deque<int>ans{n-m};
        for(int i=n-1,j=m-1;i>=0;){
            while(j>=0&&dp[i][j]){
                i--;j--;
            }
            if(i<0)break;
            for(j=m-1;!dp[i][j];j--);
            if(j==m-1){
                ans.pb(i-j);
            }
            else{
                ans.push_front(i-j);
            }
        }
        return vi(ALL(ans));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string stamp="abc";
    string target="ababc";
    auto ans=sol.movesToStamp(stamp,target);
    DBGV(ans);

    system("pause");
    return 0;
}
