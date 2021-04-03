#include "utils.h"

class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        //欧拉结构体辅助分解质因数
        static EulerPrime<100>ep;
        vi ans;
        for(auto&query:queries){
            ll res=1;
            //求出所有的因数
            vi factors=ep.getFactors<1>(k);
            //求出next数组
            vi next=next_different(factors);
            for(int i=0;i<next.size();i=next[i]){
                //此处j表示从下标i开始有几个连续的相同的因数
                int j=next[i]-i;
                //将j个因数分配到n个位置的分配方案总数为C(n+j-1,j)
                //可以想象为j个因数+(n-1)个挡板进行排队，排好队后挡板位置决定划分方案
                res=res*combination(query[0]+j-1,j)%MOD;
            }
            ans.pb(res);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi queries{
        {73,660},{1,1},{2,2},{3,3},{4,4},{5,5}
    };
    auto ans=sol.waysToFillArray(queries);
    DBGV(ans);

    system("pause");
    return 0;
}
