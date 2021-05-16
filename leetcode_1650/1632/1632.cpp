#include "Union.h"
#include "utils.h"

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        Union u(m*n);
        REP(i,m){
            static pair<int,int>points[500];
            REP(j,n)points[j]={matrix[i][j],i*n+j};
            sort(points,points+n);
            for(int k1=0,k2;k1<n;k1=k2){
                for(k2=k1+1;k2<n&&points[k2].first==points[k1].first;k2++){
                    u.unite(points[k1].second,points[k2].second);
                }
            }
        }
        REP(j,n){
            static pair<int,int>points[500];
            REP(i,m)points[i]={matrix[i][j],i*n+j};
            sort(points,points+n);
            for(int k1=0,k2;k1<m;k1=k2){
                for(k2=k1+1;k2<m&&points[k2].first==points[k1].first;k2++){
                    u.unite(points[k1].second,points[k2].second);
                }
            }
        }
        vector<pair<int,int>> points;
        vi rowmax(m,0),colmax(n,0);
        vvi ans(m,vi(n,0));
        REP(i,m)REP(j,n)points.emplace_back(matrix[i][j],i*n+j);
        sort(ALL(points));
        for(int i=0,j;i<points.size();i=j){
            for(j=i+1;j<points.size()&&points[j].first==points[i].first;j++);
            FOR(k,i,j){
                int find=u.Find(points[k].second);
                int i=points[k].second/n,j=points[k].second%n;
                int ii=find/n,jj=find%n;
                chmax(ans[ii][jj],max(rowmax[i],colmax[j])+1);
            }
            FOR(k,i,j){
                int find=u.Find(points[k].second);
                int i=points[k].second/n,j=points[k].second%n;
                int ii=find/n,jj=find%n;
                ans[i][j]=ans[ii][jj];
                chmax(rowmax[i],ans[i][j]);
                chmax(colmax[j],ans[i][j]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[1,2],[3,4]]");
    auto ans=sol.matrixRankTransform(matrix);
    DBGVV(ans);

    system("pause");
    return 0;
}
