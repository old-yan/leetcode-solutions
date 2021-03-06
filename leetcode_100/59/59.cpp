#include "utils.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i=0,j=0,val=1,idx=0;
        vvi ans(n,vi(n,0));
        while(val<=n*n){
            ans[i][j]=val++;
            int ii=i+di[idx],jj=j+dj[idx];
            if(ii<0||ii>=n||jj<0||jj>=n||ans[ii][jj]){
                idx=(idx+3)%4;
                ii=i+di[idx],jj=j+dj[idx];
            }
            i=ii,j=jj;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    auto ans=sol.generateMatrix(n);
    DBGVV(ans);

    system("pause");
    return 0;
}
