#include "utils.h"

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum=accumulate(ALL(chalk),0ll);
        k%=sum;
        REP(i,chalk.size()){
            k-=chalk[i];
            if(k<0)return i;
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
