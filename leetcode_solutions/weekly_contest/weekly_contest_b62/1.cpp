#include "utils.h"

class Solution {
public:
    //简单模拟
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        //先看数组长度对不对
        if(original.size()!=m*n)return {};
        //对的话就往二维数组里填数
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=original[i*n+j];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi original{1,2,3,4};
    int m=2;
    int n=2;
    auto ans=sol.construct2DArray(original,m,n);
    DBGVV(ans);

    system("pause");
    return 0;
}