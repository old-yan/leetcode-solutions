#include "utils.h"

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        vi nonzero;
        for(int a:nums)if(a){
            nonzero.pb(a);
        }
        sort(ALL(nonzero));
        FOR(i,1,nonzero.size())if(nonzero[i]==nonzero[i-1])return false;
        return nonzero.back()-nonzero.front()<=4;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4,5};
    auto ans=sol.isStraight(nums);
    DBG(ans);

    system("pause");
    return 0;
}
