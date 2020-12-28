#include "utils.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=m-1,j=0;
        while(i>=0&&j<n){
            if(matrix[i][j]==target)return true;
            if(matrix[i][j]<target)j++;
            else i--;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix{
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    auto ans=sol.searchMatrix(matrix,19);
    DBG(ans);

    system("pause");
    return 0;
}
