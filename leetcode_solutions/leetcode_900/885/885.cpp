#include "utils.h"

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vvi ans;
        int m=R,n=C,k=0,l1=1,l2=1;
        int ii=r0,jj=c0;
        while(ans.size()<m*n){
            if(VALID)ans.pb({ii,jj});
            ii+=di[k];
            jj+=dj[k];
            if(!--l1){
                k=(k+3)%4;
                l1=l2;
                if(k%2)l2++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int R=1;
    int C=4;
    int r0=0;
    int c0=0;
    auto ans=sol.spiralMatrixIII(R,C,r0,c0);
    DBGVV(ans);

    system("pause");
    return 0;
}
