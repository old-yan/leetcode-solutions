#include "utils.h"

class Solution {
public:
    bool checkPowersOfThree(int n) {
        //将3的所有幂都手动列出来
        static vi material{1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969};
        //计算出用上述材料所能拼出来的所有的子序列和
        static vi v=getSubsequenceSum(material);
        //看看n在不在里面
        auto it=lower_bound(ALL(v),n);
        return it!=v.end()&&*it==n;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=21;
    auto ans=sol.checkPowersOfThree(n);
    DBG(ans);
    
    system("pause");
    return 0;
}
