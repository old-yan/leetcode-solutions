#include "utils.h"

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(!m)return {};
        int n=matrix[0].size();
        int i=0,j=0,di=-1,dj=1;
        vi ans;
        while(true){
            ans.pb(matrix[i][j]);
            if(ans.size()==m*n)break;
            int ii=i+di,jj=j+dj;
            if(ii<0||ii>=m||jj<0||jj>=n){
                if(di<0){
                    ii=i,jj=j+1;
                    if(ii<0||ii>=m||jj<0||jj>=n){
                        ii=i+1,jj=j;
                    }
                }
                else{
                    ii=i+1,jj=j;
                    if(ii<0||ii>=m||jj<0||jj>=n){
                        ii=i,jj=j+1;
                    }
                }
                di*=-1;
                dj*=-1;
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

    vvi matrix{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    auto ans=sol.findDiagonalOrder(matrix);
    DBGV(ans);

    system("pause");
    return 0;
}
