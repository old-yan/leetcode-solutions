#include "utils.h"

class Solution {
public:
    int binaryGap(int n) {
        if(__builtin_popcount(n)==1)return 0;
        bitset<32>b(n);
        int ans=0;
        for(int i=b._Find_first(),j=b._Find_next(i);j<32;i=j,j=b._Find_next(j)){
            chmax(ans,j-i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.binaryGap(n);
    DBG(ans);

    system("pause");
    return 0;
}
