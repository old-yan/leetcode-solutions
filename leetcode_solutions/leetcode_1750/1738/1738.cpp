#include "utils.h"

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        int ans=INT_MIN;
        REP(i,m){
            int sum=0;
            REP(j,n){
                sum^=matrix[i][j];
                matrix[i][j]=i?sum^matrix[i-1][j]:sum;
                chmax(ans,matrix[i][j]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[5,2],[1,6]]");
    int k=1;
    auto ans=sol.kthLargestValue(matrix,k);
    DBG(ans);

    system("pause");
    return 0;
}
