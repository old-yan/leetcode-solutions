#include "utils.h"

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double a[100][100]={0};
        a[0][0]=poured;
        FOR(i,1,query_row+1){
            REP(j,i){
                if(a[i-1][j]>1){
                    a[i][j]+=(a[i-1][j]-1)/2;
                    a[i][j+1]+=(a[i-1][j]-1)/2;
                }
            }
        }
        return min(1.0,a[query_row][query_glass]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int poured=1;
    int query_row=1;
    int query_glass=1;
    auto ans=sol.champagneTower(poured,query_row,query_glass);
    DBG(ans);

    system("pause");
    return 0;
}
