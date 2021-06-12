#include "utils.h"

class Solution {
public:
    //直接模拟可能超时，因为k可能有几亿，如果chalk全是1，那得减到猴年马月
    //可以先把前面那些能走完的圈走完，也就是先算出一圈的数量，再对圈取余，直接空降到一定会缺粉笔的那一圈
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum=accumulate(ALL(chalk),0ll);
        k%=sum;
        REP(i,chalk.size()){
            if(k<chalk[i])return i;
            k-=chalk[i];
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi chalk{5,1,5};
    int k=22;
    auto ans=sol.chalkReplacer(chalk,k);
    DBG(ans);

    system("pause");
    return 0;
}
