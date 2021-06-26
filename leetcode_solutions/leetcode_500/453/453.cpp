#include "utils.h"

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int Min=*min_element(ALL(nums));
        int extra=0;
        for(int a:nums){
            extra+=a-Min;
        }
        return extra;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3};
    auto ans=sol.minMoves(nums);
    DBG(ans);

    system("pause");
    return 0;
}
