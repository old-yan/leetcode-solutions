#include "utils.h"

class Solution {
public:
    //注意到移动方向只能向右/向下，所以第一个人的轨迹必然是一个"z"字形
    //那么这个"z"字上的点数会被置为0
    //第二个人要么从一开始就到第二行去收集左边的点数，要么一直呆在第一行收集右边的点数
    //我们只要枚举"z"字的拐弯处的列号，就可以涵盖所有可能性
    long long gridGame(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        //求出第一行前缀和
        vector<ll>sum1(ALL(grid[0]));
        partial_sum(ALL(sum1),sum1.begin());
        //求出第二行前缀和
        vector<ll>sum2(ALL(grid[1]));
        partial_sum(ALL(sum2),sum2.begin());
        ll ans=LLONG_MAX;
        //枚举拐弯处的列号
        for(int j=0;j<n;j++)
            ans=min(ans,max(sum2[j-1],sum1.back()-sum1[j]));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi grid=makevvi("[[2,5,4],[1,5,1]]");
    auto ans=sol.gridGame(grid);
    DBG(ans);

    system("pause");
    return 0;
}