#include "utils.h"

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base=minutesToTest/minutesToDie+1;
        int ans=ceil(log(buckets)/log(base));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int buckets=1000;
    int minutesToDie=15;
    int minutesToTest=60;
    auto ans=sol.poorPigs(buckets,minutesToDie,minutesToTest);
    DBG(ans);

    system("pause");
    return 0;
}
