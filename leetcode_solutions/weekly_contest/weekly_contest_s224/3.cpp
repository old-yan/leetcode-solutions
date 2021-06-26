#include "utils.h"

class Solution {
    #define ll long long
public:
    int largestSubmatrix(vector<vector<int>>& ma) {
        int m=ma.size(),n=ma[0].size();
        //above[i][j]表示在原二维数组(i,j)位置上摞着几个1
        vvi above(m,vi(n,0));
        //预处理求出全部的above
        REP(i,m){
            REP(j,n){
                if(!i)above[i][j]=ma[i][j];
                else if(ma[i][j])above[i][j]=above[i-1][j]+1;
            }
        }
        //对每行的above进行计算，如果以本行作为最终子矩形下沿，则最大面积为多少
        ll ans=0;
        REP(i,m){
            //above第i行升序排列
            sort(ALL(above[i]));
            //升序排列之后，某个值之后的都比自己大，以自己身高above[i][j]为高，则底为(n-j)
            REP(j,n){
                chmax(ans,above[i][j]*(n-j));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi ma{
        {0,0,1},{1,1,1},{1,0,1}
    };
    auto ans=sol.largestSubmatrix(ma);
    DBG(ans);

    system("pause");
    return 0;
}
