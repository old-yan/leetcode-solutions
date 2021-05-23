#include "utils.h"

class Solution {
    bool connect[400][400]={0};
    int deg[400]={0};
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        for(auto&e:edges){
            int i=e[0]-1,j=e[1]-1;
            connect[i][j]=connect[j][i]=true;
            deg[i]++;
            deg[j]++;
        }
        int ans=INT_MAX;
        REP(i,n){
            REP(j,i)if(connect[i][j]){
                REP(k,j)if(connect[i][k]&&connect[j][k]){
                    chmin(ans,deg[i]+deg[j]+deg[k]-3);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=6;
    vvi edges=makevvi("[[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]");
    auto ans=sol.minTrioDegree(n,edges);
    DBG(ans);

    system("pause");
    return 0;
}
