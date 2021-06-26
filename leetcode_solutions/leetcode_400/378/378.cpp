#include "utils.h"

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        ll low=matrix[0][0],high=matrix.back().back();
        while(low<high){
            ll mid=(low+high)/2;
            int i=n-1,j=0,count=0;
            while(i>=0){
                while(j<n&&matrix[i][j]<=mid)j++;
                count+=j;
                i--;
            }
            if(count>=k)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix{
        {1,5,9},
        {10,11,13},
        {12,13,15}
    };
    int k=8;
    auto ans=sol.kthSmallest(matrix,k);
    DBG(ans);

    system("pause");
    return 0;
}
