#include "utils.h"

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        sort(ALLR(nums),[](int x,int y){return x%2<y%2;});
        return nums;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4};
    auto ans=sol.exchange(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
