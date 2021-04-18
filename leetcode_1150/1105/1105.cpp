#include "utils.h"

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n=books.size();
        int _dp[n+1];
        auto dp=_dp+1;
        memset(_dp,0x3f,sizeof(_dp));
        _dp[0]=0;
        REP(i,n){
            int w=0,h=0;
            REPR(j,i){
                w+=books[j][0];
                chmax(h,books[j][1]);
                if(w>shelf_width)break;
                chmin(dp[i],dp[j-1]+h);
            }
        }
        return dp[n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi books=makevvi("[[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]");
    int shelf_width=4;
    auto ans=sol.minHeightShelves(books,shelf_width);
    DBG(ans);

    system("pause");
    return 0;
}
