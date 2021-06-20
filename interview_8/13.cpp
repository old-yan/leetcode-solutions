#include "utils.h"

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        int n=box.size();
        int dp[n];
        sort(ALL(box));
        REP(i,n){
            dp[i]=box[i][2];
            REP(j,i){
                if(box[j][0]<box[i][0]&&box[j][1]<box[i][1]&&box[j][2]<box[i][2]){
                    chmax(dp[i],dp[j]+box[i][2]);
                }
            }
        }
        return *max_element(dp,dp+n);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi box=makevvi("[[1, 1, 1], [2, 2, 2], [3, 3, 3]]");
    auto ans=sol.pileBox(box);
    DBG(ans);

    system("pause");
    return 0;
}
