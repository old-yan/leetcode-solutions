#include "utils.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(!m)return false;
        int n=matrix[0].size();
        int j=n;
        REP(i,m){
            while(j&&matrix[i][j-1]>=target)j--;
            if(j<n&&matrix[i][j]==target)return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix=makevvi("[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]");
    int target=5;
    auto ans=sol.searchMatrix(matrix,target);
    DBG(ans);

    system("pause");
    return 0;
}
