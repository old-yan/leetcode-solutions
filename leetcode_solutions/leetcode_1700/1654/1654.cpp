#include "utils.h"

class Solution {
public:
    int minimumJumps(vector<int>& _forbidden, int a, int b, int x) {
        bool forbidden[20000]={0};
        for(int a:_forbidden)forbidden[a]=true;
        int dp[20000][2];
        memset(dp,0x3f,sizeof(dp));
        queue<tuple<int,int,int>>Q;
        dp[0][0]=dp[0][1]=0;
        Q.emplace(0,0,0);
        while(Q.size()){
            auto [dis,cur,dir]=Q.front();
            Q.pop();
            if(cur==x)return dis;
            if(dis!=dp[cur][dir])continue;
            if(cur+a<20000&&!forbidden[cur+a]&&chmin(dp[cur+a][0],dis+1)){
                Q.emplace(dis+1,cur+a,0);
            }
            if(!dir&&cur-b>=0&&!forbidden[cur-b]&&chmin(dp[cur-b][1],dis+1)){
                Q.emplace(dis+1,cur-b,1);
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi forbidden{14,4,18,1,15};
    int a=3;
    int b=15;
    int x=9;
    auto ans=sol.minimumJumps(forbidden,a,b,x);
    DBG(ans);

    system("pause");
    return 0;
}
