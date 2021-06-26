#include "utils.h"

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int matrix[N][N]={0};
        for(auto&mine:mines){
            matrix[mine[0]][mine[1]]=1;
        }
        int up[N][N],down[N][N],left[N][N],right[N][N];
        #define up(i,j) (i>=0?up[i][j]:0)
        REP(i,N)REP(j,N)up[i][j]=matrix[i][j]?0:up(i-1,j)+1;
        #define down(i,j) (i<N?down[i][j]:0)
        REPR(i,N-1)REP(j,N)down[i][j]=matrix[i][j]?0:down(i+1,j)+1;
        #define left(i,j) (j>=0?left[i][j]:0)
        REP(i,N)REP(j,N)left[i][j]=matrix[i][j]?0:left(i,j-1)+1;
        #define right(i,j) (j<N?right[i][j]:0)
        REP(i,N)REPR(j,N-1)right[i][j]=matrix[i][j]?0:right(i,j+1)+1;
        int ans=0;
        REP(i,N){
            REP(j,N){
                chmax(ans,min(min(up[i][j],down[i][j]),min(left[i][j],right[i][j])));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=5;
    vvi mines={{4,2}};
    auto ans=sol.orderOfLargestPlusSign(N,mines);
    DBG(ans);

    system("pause");
    return 0;
}
