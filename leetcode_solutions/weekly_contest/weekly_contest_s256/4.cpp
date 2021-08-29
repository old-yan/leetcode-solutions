#include "utils.h"

class Solution {
public:
    //经典本质不同子序列问题，由于不要前导零，所以从后往前递推，关注当前字母做首字母的时候是否为前导零
    int numberOfUniqueGoodSubsequences(string binary) {
        // startwith0 和 startwith1 记录以 '0' 和 '1' 作为开端的子序列数目
        ll startwith0=0,startwith1=0;
        // last0 和 last1 记录上次遇到 '0' 和 '1' 作为开端的子序列数目
        ll last0=0,last1=0;
        for(int i=binary.size()-1;i>=0;i--){
            char c=binary[i];
            if(c=='0'){
                //选取当前字符'0'作为开端字母，则可以更新 startwith0 的数量
                startwith0+=1+startwith0+startwith1;
                //这里为什么要减去 last0
                //首先，startwith0 的新增部分是由当前的 '0' 结合后面的子序列拼凑出来的
                //但是，在上次遇到的 '0' 后面的子序列，已经和上次遇到的 '0' 结合过了，再和当前的 '0' 结合，妥妥的重复
                //所以，last0 正好就是重复的数量，把这部分减掉就是去重。
                startwith0=(startwith0-last0+MOD)%MOD;
                last0=startwith0;
            }
            else{
                //分析过程同上
                startwith1+=1+startwith0+startwith1;
                startwith1=(startwith1-last1+MOD)%MOD;
                last1=startwith1;
            }
        }
        //记得有零就得加个空串
        if(count(ALL(binary),'0'))return (startwith1+1)%MOD;
        else return startwith1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string binary="101";
    auto ans=sol.numberOfUniqueGoodSubsequences(binary);
    DBG(ans);

    system("pause");
    return 0;
}
