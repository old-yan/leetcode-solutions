#include "utils.h"

class Solution {
public:
    //这个题的二维网格完全是个幌子，直接把二维摊到一维做
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size(),n=grid[0].size();
        //把二维网格摊到一维的vector里
        vector<int>v;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++)v.push_back(grid[i][j]);
        //排序
        sort(v.begin(),v.end());
        //间隔差必须是x的倍数
        for(int i=1;i<v.size();i++){
            int d=v[i]-v[i-1];
            if(d%x)return -1;
        }
        //靠拢的目标是中位数（注意是中位数不是平均数；如果中位数有两个，随便靠拢一个就可以）
        int mid=v[v.size()/2];
        long long sum=0;
        for(int a:v){
            sum+=abs(a-mid);
        }
        return sum/x;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<int>>grid=makevvi("[[2,4],[6,8]]");
    int x=2;
    auto ans=sol.minOperations(grid,x);
    DBG(ans);

    system("pause");
    return 0;
}