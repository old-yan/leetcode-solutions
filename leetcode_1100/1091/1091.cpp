#include "Heap.h"
#include "utils.h"

class Solution {
    int dis[100][100];
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=n;
        if(grid[0][0]||grid[n-1][n-1])return -1;
        memset(dis,0x3f,sizeof(dis));
        dis[0][0]=1;
        #define dis(a) dis[a/n][a%n]
        Heap<int>H([&](int x,int y){return dis(x)>dis(y);});
        H.push(0);
        while(H.size()){
            auto p=H.top();
            H.pop();
            int i=p/n,j=p%n;
            FOR(ii,i-1,i+2){
                FOR(jj,j-1,j+2){
                    if(VALID&&!grid[ii][jj]&&chmin(dis[ii][jj],dis(p)+1)){
                        H.push(ii*n+jj);
                    }
                }
            }
        }
        return dis[n-1][n-1]==0x3f3f3f3f?-1:dis[n-1][n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[0,0,0],[1,1,0],[1,1,0]]");
    auto ans=sol.shortestPathBinaryMatrix(grid);
    DBG(ans);

    system("pause");
    return 0;
}
