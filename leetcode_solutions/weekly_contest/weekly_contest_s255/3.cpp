#include "utils.h"

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        //先测试一下每行取最小会不会超标
        int minsum=0;
        for(auto&v:mat){
            int a=*min_element(v.begin(),v.end());
            minsum+=a;
        }
        //如果每行取最小都超出target，那么每行取最小显然是最佳方案
        if(minsum>=target)return minsum-target;

        //背包获取 [0,target*2]范围内的数字的可行性
        //dp[i][j]表示下标i及i之前，是否能凑出j
        bool dp[mat.size()][target*2+1];
        memset(dp,0,sizeof(dp));
        //经典背包，我写成二维形式
        for(int i=0;i<mat.size();i++){
            if(i==0){
                for(int a:mat[i])if(a<=target*2){
                    dp[i][a]=true;
                }
            }
            else{
                for(int j=0;j<=target*2;j++){
                    for(int a:mat[i])if(a<=j&&dp[i-1][j-a]){
                        dp[i][j]=true;
                        break;
                    }
                }
            }
        }
        int ans=100000;
        for(int i=0;i<=target*2;i++){
            if(dp[mat.size()-1][i]){
                ans=min(ans,abs(i-target));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi mat=makevvi("[[1,2,9,8,7]]");
    int target=6;
    auto ans=sol.minimizeTheDifference(mat,target);
    DBG(ans);

    system("pause");
    return 0;
}
