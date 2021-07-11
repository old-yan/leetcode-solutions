#include "utils.h"

class Solution {
    //from数组存放每种状态的前趋状态
    vector<int>from[243];
    //good数组存放每种状态的合法性
    bool good[243]={0};
    //检查某一列的颜色自身是否合法
    bool valid(int col[],int m){
        for(int i=1;i<m;i++){
            if(col[i]==col[i-1])return false;
        }
        return true;
    }
    //检查某两列的颜色之间是否合法
    bool valid(int col1[],int col2[],int m){
        for(int i=0;i<m;i++){
            if(col1[i]==col2[i])return false;
        }
        return true;
    }
    void init(int m){
        int all=pow(3,m);
        for(int cur=0;cur<all;cur++){
            //将三进制数 curstate 展开到 a 数组
            int a[m];
            for(int i=0,j=cur;i<m;i++)a[i]=j%3,j/=3;
            if(!valid(a,m))continue;
            else good[cur]=true;
            for(int pre=0;pre<all;pre++){
                //将三进制数 prestate 展开到 b 数组
                int b[m];
                for(int i=0,j=pre;i<m;i++)b[i]=j%3,j/=3;
                if(!valid(b,m))continue;
                if(valid(a,b,m))from[cur].push_back(pre);
            }
        }
    }
public:
    //这道题从数据看，就可能是动态规划，而且是从左面的列，向右面的列进行转移
    int colorTheGrid(int m, int n) {
        //令 dp[i][state] 表示第 i 列，染色状态为 state 的方案数
        //注意到，染色是在 5 个位置上，每个位置三个选择，那么总共有 pow(3,5) 种染色状态
        //我们可以预处理一下 状态与状态之间的转移连通性，这样在计算 dp[i][curstate] 的时候直接找 curstate 的前置状态就可以了
        init(m);
        ll dp[n][243],all=pow(3,m);
        memset(dp,0,sizeof(dp));
        //计算第一列
        {
            int i=0;
            for(int cur=0;cur<all;cur++){
                if(good[cur])dp[i][cur]=1;
            }
        }
        //计算之后的列
        for(int i=1;i<n;i++)
            for(int cur=0;cur<all;cur++)
                if(good[cur])
                    for(int pre:from[cur])
                        dp[i][cur]=(dp[i][cur]+dp[i-1][pre])%1000000007;
        //对最后一列的方案数汇总输出
        return accumulate(dp[n-1],dp[n],0ll)%1000000007;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int m=5;
    int n=5;
    auto ans=sol.colorTheGrid(m,n);
    DBG(ans);

    system("pause");
    return 0;
}
