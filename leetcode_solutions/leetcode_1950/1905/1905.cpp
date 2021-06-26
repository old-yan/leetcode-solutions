#include "Union.h"
#include "utils.h"

Union u1(250000),u2(250000);
class Solution {
    int m,n;
    void func(vvi&g,Union&u){
        REP(i,m)REP(j,n)if(g[i][j])REP(k,4){
            int ii=i+di[k],jj=j+dj[k];
            if(!VALID)continue;
            if(g[ii][jj])u.unite(i*n+j,ii*n+jj);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        u1.reset(),u2.reset();
        m=grid2.size(),n=grid2[0].size();
        func(grid1,u1);
        func(grid2,u2);
        unordered_map<int,vector<pair<int,int>>>M;
        REP(i,m)REP(j,n)if(grid2[i][j]){
            M[u2.Find(i*n+j)].emplace_back(i,j);
        }
        int ans=0;
        for(auto&it:M){
            int find=-1;
            bool same=true;
            for(auto [i,j]:it.second){
                int k=u1.Find(i*n+j);
                if(find<0){
                    int ii=k/n,jj=k%n;
                    if(grid1[ii][jj])find=k;
                    else{
                        same=false;break;
                    }
                }
                else if(find==k)continue;
                else{
                    same=false;break;
                }
            }
            if(same)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    

    system("pause");
    return 0;
}
