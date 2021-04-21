#include "utils.h"

class Solution {
    vi piles;
    pair<int,int>dp[105][105];
    pair<int,int> fun(int cur,int M){
        if(dp[cur][M].first)return dp[cur][M];
        if(cur==piles.size())return {0,0};
        int a=0;
        pair<int,int>res{0,0};
        FOR(i,1,M*2+1){
            if(cur+i-1==piles.size())break;
            a+=piles[cur+i-1];
            auto p=fun(cur+i,max(M,int(i)));
            swap(p.first,p.second);
            p.first+=a;
            chmax(res,p);
        }
        return dp[cur][M]=res;
    }
public:
    int stoneGameII(vector<int>& _piles) {
        fill(dp[0],dp[piles.size()],make_pair(0,0));
        piles=_piles;
        return fun(0,1).first;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi piles{2,7,9,4,4};
    auto ans=sol.stoneGameII(piles);
    DBG(ans);

    system("pause");
    return 0;
}
