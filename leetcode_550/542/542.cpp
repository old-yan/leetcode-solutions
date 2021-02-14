#include "utils.h"

class Solution {
    struct pos{
        int i,j,dis;
        pos(int _i,int _j,int _dis):i(_i),j(_j),dis(_dis){}
    };
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vvi ans(m,vi(n,INT_MAX));
        auto comp=[&](pos&x,pos&y){return x.dis>y.dis;};
        priority_queue<pos,vector<pos>,decltype(comp)>Q(comp);
        REP(i,m){
            REP(j,n){
                if(matrix[i][j]==0){
                    ans[i][j]=0;
                    Q.emplace(i,j,ans[i][j]);
                }
            }
        }
        while(Q.size()){
            auto p=Q.top();
            Q.pop();
            int i=p.i,j=p.j;
            REP(k,4){
                int ii=i+di[k],jj=j+dj[k];
                if(VALID&&ans[ii][jj]>p.dis){
                    ans[ii][jj]=p.dis+1;
                    Q.emplace(ii,jj,ans[ii][jj]);
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
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    auto ans=sol.updateMatrix(matrix);
    DBGVV(ans);

    system("pause");
    return 0;
}
