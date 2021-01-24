#include "utils.h"

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        //使用二维数组g存放异或结果
        int g[m][n];
        REP(i,m){
            //使用k存放本行的前缀异或和
            int k=0;
            REP(j,n){
                k^=matrix[i][j];
                if(!i)g[i][j]=k;
                else g[i][j]=g[i-1][j]^k;
            }
        }
        //无需考虑什么大顶堆，直接排序搞定
        int *all=g[0];
        sort(all,all+m*n);
        return all[m*n-k];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix{
        {5,2},{1,6}
    };
    int k=3;
    auto ans=sol.kthLargestValue(matrix,k);
    DBG(ans);

    system("pause");
    return 0;
}
