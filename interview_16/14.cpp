#include "utils.h"

class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
        int n=points.size();
        if(n==2)return {0,1};
        double mat[n][300];
        REP(i,n)REP(j,n)mat[i][j]=atan2(points[j][1]-points[i][1],points[j][0]-points[i][0]);
        vi idxes(n);
        iota(ALL(idxes),0);
        sort(ALL(idxes),[&](int x,int y){return points[x]<points[y];});
        tuple<int,int,int>ans{0,0,0};
        REP(cur,n-1){
            vi copy(idxes.begin()+cur+1,idxes.end());
            int idx=idxes[cur];
            sort(ALL(copy),[&](int x,int y){return mat[idx][x]<mat[idx][y];});
            for(int i=0,j;i<copy.size();i=j){
                for(j=i+1;j<copy.size()&&abs(mat[idx][copy[j]]-mat[idx][copy[i]])<EPS;j++);
                static int seq[300];
                FOR(k,i,j)seq[k-i]=copy[k];
                seq[j-i]=idx;
                sort(seq,seq+j-i+1);
                chmin(ans,tuple{i-j-1,seq[0],seq[1]});
            }
        }
        return {get<1>(ans),get<2>(ans)};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[0,0],[1,1],[1,0],[2,0]]");
    auto ans=sol.bestLine(points);
    DBGV(ans);

    system("pause");
    return 0;
}
