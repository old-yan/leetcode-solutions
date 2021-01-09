#include "utils.h"

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        queue<pair<int,int>>Q;
        bool pacific[m][n];
        memset(pacific,0,sizeof(pacific));
        FOR(i,1,m){
            Q.emplace(i,0);
            pacific[i][0]=true;
        }
        REP(j,n){
            Q.emplace(0,j);
            pacific[0][j]=true;
        }
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            REP(k,4){
                int ii=p.first+di[k],jj=p.second+dj[k];
                if(ii>=0&&ii<m&&jj>=0&&jj<n&&matrix[ii][jj]>=matrix[p.first][p.second]&&!pacific[ii][jj]){
                    Q.emplace(ii,jj);
                    pacific[ii][jj]=true;
                }
            }
        }
        bool atlantic[m][n];
        memset(atlantic,0,sizeof(atlantic));
        REP(i,m-1){
            Q.emplace(i,n-1);
            atlantic[i][n-1]=true;
        }
        REP(j,n){
            Q.emplace(m-1,j);
            atlantic[m-1][j]=true;
        }
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            REP(k,4){
                int ii=p.first+di[k],jj=p.second+dj[k];
                if(ii>=0&&ii<m&&jj>=0&&jj<n&&matrix[ii][jj]>=matrix[p.first][p.second]&&!atlantic[ii][jj]){
                    Q.emplace(ii,jj);
                    atlantic[ii][jj]=true;
                }
            }
        }
        vvi ans;
        REP(i,m){
            REP(j,n){
                if(pacific[i][j]&&atlantic[i][j]){
                    ans.pb({int(i),int(j)});
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

    vvi matrix{
        {1,1},{1,1},{1,1}
    };
    auto ans=sol.pacificAtlantic(matrix);
    DBGVV(ans);

    system("pause");
    return 0;
}
