#include "utils.h"

class Solution {
    int m,n;
    int biggerline(vector<vector<int>>& matrix,int target){
        int low = 0,high = m;
        while (low<high){
            int mid = (high + low) / 2;
            if (matrix[mid][0]>target)high = mid;
            else low = mid+1;
        }
        return low;
    }
    int lowerbound(vi&row,int target){
        int low = 0,high = n;
        while (low<high){
            int mid = (high + low) / 2;
            if (row[mid]>=target)high = mid;
            else low = mid+1;
        }
        return low;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m=matrix.size();
        if(!m)return false;
        n=matrix[0].size();bs
        if(!n)return false;
        int i=biggerline(matrix,target)-1;
        if(i<0)return false;
        int j=lowerbound(matrix[i],target);
        return j<n&&matrix[i][j]==target;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix{
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,50}
    };
    int target=13;
    auto ans=sol.searchMatrix(matrix,target);
    DBG(ans);

    system("pause");
    return 0;
}
