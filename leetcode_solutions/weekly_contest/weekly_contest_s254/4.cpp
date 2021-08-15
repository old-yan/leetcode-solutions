#include "utils.h"
#include "Union.h"

class Solution {
public:
    //本题一看就是判断连通性，但是是判断什么时候失去连通性
    //常规的并查集并不支持将已经连通的组分和组分拆开，我们可以换个思路，从后往前，看什么时候连通
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int m=row,n=col;
        //并查集大小多个2，[0,m*n-1]用来表示格点，m*n用来连第一行，m*n+1用来连最后一行
        Union u(m*n+2);
        bool land[m][n];
        memset(land,0,sizeof(land));
        //下标从大到小
        REPR(cur,cells.size()-1){
            int i=cells[cur][0]-1,j=cells[cur][1]-1;
            land[i][j]=true;
            if(i==0)u.unite(i*n+j,m*n);
            if(i==m-1)u.unite(i*n+j,m*n+1);
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(VALID&&land[ii][jj]){
                    u.unite(i*n+j,ii*n+jj);
                }
            }
            //一旦连通，说明这里是交界处
            if(u.same(m*n,m*n+1)){
                return cur;
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int row=2;
    int col=2;
    vvi cells=makevvi("[[1,1],[2,1],[1,2],[2,2]]");
    auto ans=sol.latestDayToCross(row,col,cells);
    DBG(ans);

    system("pause");
    return 0;
}
