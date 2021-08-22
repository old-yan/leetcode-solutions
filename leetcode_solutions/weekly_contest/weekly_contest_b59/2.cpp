#include "utils.h"

class Solution {
public:
    //这道题一定要想清楚一点：那就是可以翻转相邻两点，就相当于可以翻转任意两点
    //可以在纸上模拟一下，如果拉一条 甲点 到 乙点 的路线，然后把路线上相邻点都翻转
    //那么路线上的每个点都会翻转两次，等于没有翻转；只有甲和乙翻了一次
    //那么问题就简单了，尽量把所有数变成正的就行
    //如果有奇数个负数，总会有数字不能翻成正的，那么就让数组里绝对值最小的数字为负
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),neg=0,Minabs=100000;
        long long sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=0)neg++;
                Minabs=min(Minabs,abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }
        if(neg%2==0)return sum;
        else return sum-Minabs*2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi matrix{
        {1,2,3},{-1,-2,-3},{1,2,3}
    };
    auto ans=sol.maxMatrixSum(matrix);
    DBG(ans);

    system("pause");
    return 0;
}
