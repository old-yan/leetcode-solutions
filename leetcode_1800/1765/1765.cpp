#include "utils.h"

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size();
        vvi ans(m,vi(n,0));
        queue<tuple<int,int,int>>Q;
        REP(i,m)REP(j,n)if(isWater[i][j])Q.emplace(i,j,0);
        while(Q.size()){
            auto [i,j,h]=Q.front();
            Q.pop();
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(!VALID)continue;
                if(!isWater[ii][jj]&&!ans[ii][jj]){
                    ans[ii][jj]=h+1;
                    Q.emplace(ii,jj,h+1);
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi isWater=makevvi("[[0,1],[0,0]]");
    auto ans=sol.highestPeak(isWater);
    DBGVV(ans);

    system("pause");
    return 0;
}
