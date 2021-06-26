#include "utils.h"

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int sum=accumulate(ALL(nums),0,[](int x,int y){return x^y;});
        return !sum||nums.size()%2==0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,0,1};
    auto ans=sol.xorGame(nums);
    DBG(ans);

    system("pause");
    return 0;
}
