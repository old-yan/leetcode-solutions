#include "utils.h"

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(!m)return false;
        int n=matrix[0].size();
        for(int i=0,j=n;i<m;i++){
            while(j-1>=0&&matrix[i][j-1]>=target)j--;
            if(matrix[i][j]==target)return true;
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
    auto ans=sol.findNumberIn2DArray(matrix,target);
    DBG(ans);

    system("pause");
    return 0;
}
