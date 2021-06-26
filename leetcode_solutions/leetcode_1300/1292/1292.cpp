#include "utils.h"

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size(),n=mat[0].size();
        int presum[m+1][n+1];
        memset(presum,0,sizeof(presum));
        REP(i,m)REP(j,n){
            presum[i+1][j+1]=presum[i+1][j]+mat[i][j]+presum[i][j+1]-presum[i][j];
        }
        int ans=0;
        REP(i,m)REP(j,n){
            for(int ii=i,jj=j;ii<m&&jj<n;ii++,jj++){
                int areasum=presum[ii+1][jj+1]+presum[i][j]-presum[ii+1][j]-presum[i][jj+1];
                if(areasum<=threshold)chmax(ans,ii-int(i)+1);
                else break;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]]");
    int threshold=4;
    auto ans=sol.maxSideLength(mat,threshold);
    DBG(ans);

    system("pause");
    return 0;
}
