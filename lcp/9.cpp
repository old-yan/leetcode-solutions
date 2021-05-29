#include "utils.h"

class Solution {
public:
    int minJump(vector<int>& jump) {
        int n=jump.size();
        int cur=0;
        int dp[n];
        memset(dp,0x3f,sizeof(dp));
        queue<int>Q;
        dp[cur]=0;
        Q.push(cur++);
        while(true){
            auto p=Q.front();
            if(p+jump[p]>=n)return dp[p]+1;
            else if(chmin(dp[p+jump[p]],dp[p]+1)){
                Q.push(p+jump[p]);
            }
            Q.pop();
            while(cur<p){
                if(chmin(dp[cur],dp[p]+1)){
                    Q.push(cur);
                }
                cur++;
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi jump{2, 5, 1, 1, 1, 1};
    auto ans=sol.minJump(jump);
    DBG(ans);

    system("pause");
    return 0;
}
