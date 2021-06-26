#include "Union.h"
#include "utils.h"

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        Union u(m*n*4);
        REP(i,m){
            REP(j,n){
                if(grid[i][j]==' '){
                    u.unite(i*n*4+j*4+0,i*n*4+j*4+1);
                    u.unite(i*n*4+j*4+0,i*n*4+j*4+2);
                    u.unite(i*n*4+j*4+0,i*n*4+j*4+3);
                    REP(k,4){
                        int ii=i+di[k],jj=j+dj[k];
                        if(ii>=0&&ii<m&&jj>=0&&jj<n){
                            u.unite(i*n*4+j*4+k,ii*n*4+jj*4+(k+2)%4);
                        }
                    }
                }
                else if(grid[i][j]=='/'){
                    u.unite(i*n*4+j*4+0,i*n*4+j*4+3);
                    u.unite(i*n*4+j*4+1,i*n*4+j*4+2);
                    REP(k,4){
                        int ii=i+di[k],jj=j+dj[k];
                        if(ii>=0&&ii<m&&jj>=0&&jj<n){
                            u.unite(i*n*4+j*4+k,ii*n*4+jj*4+(k+2)%4);
                        }
                    }
                }
                else{
                    u.unite(i*n*4+j*4+0,i*n*4+j*4+1);
                    u.unite(i*n*4+j*4+3,i*n*4+j*4+2);
                    REP(k,4){
                        int ii=i+di[k],jj=j+dj[k];
                        if(ii>=0&&ii<m&&jj>=0&&jj<n){
                            u.unite(i*n*4+j*4+k,ii*n*4+jj*4+(k+2)%4);
                        }
                    }
                }
            }
        }
        return u.group;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>grid{
        " /","/ "
    };
    auto ans=sol.regionsBySlashes(grid);
    DBG(ans);

    system("pause");
    return 0;
}
