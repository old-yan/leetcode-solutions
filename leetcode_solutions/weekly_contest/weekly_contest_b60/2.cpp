#include "utils.h"

class Solution {
public:
    //从上往下、从左往右进行扫描，每次扫描到一个农场，一定是这个农场矩形的左上角
    //找到这个矩形的右下角之后，将这个矩形填充为0，这样之后就不会再重复扫描到它
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size(),n=land[0].size();
        vvi ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)if(land[i][j]){
                //找出举行右下角 [imax,jmax]
                int imax=i,jmax=j;
                while(imax+1<m&&land[imax+1][j])imax++;
                while(jmax+1<n&&land[i][jmax+1])jmax++;
                //填充为森林
                for(int a=i;a<=imax;a++){
                    for(int b=j;b<=jmax;b++){
                        land[a][b]=0;
                    }
                }
                ans.push_back({i,j,imax,jmax});
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[1,0,0],[0,1,1],[0,1,1]]");
    auto ans=sol.findFarmland(matrix);
    DBGVV(ans);

    system("pause");
    return 0;
}
