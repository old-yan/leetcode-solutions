#include "utils.h"

class Solution {
    bool visited[100][100]={0};
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int m=R,n=C;
        vvi ans;
        queue<pair<int,int>>Q;
        visited[r0][c0]=true;
        Q.emplace(r0,c0);
        while(int l=Q.size()){
            while(l--){
                auto [r,c]=Q.front();
                Q.pop();
                ans.pb({r,c});
                REP(k,4){
                    int ii=r+di[k],jj=c+dj[k];
                    if(VALID&&!visited[ii][jj]){
                        visited[ii][jj]=true;
                        Q.emplace(ii,jj);
                    }
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

    int R=2;
    int C=3;
    int r0=1;
    int c0=2;
    auto ans=sol.allCellsDistOrder(R,C,r0,c0);
    DBGVV(ans);

    system("pause");
    return 0;
}
