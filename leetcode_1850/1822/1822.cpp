#include "utils.h"

class Solution {
    int signFunc(int x){
        if(x>0)return 1;
        else if(x<0)return -1;
        else return 0;
    }
public:
    int arraySign(vector<int>& nums) {
        int ans=1;
        for(int a:nums)ans*=signFunc(a);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-1,-2,-3,-4,3,2,1};
    auto ans=sol.arraySign(nums);
    DBG(ans);

    system("pause");
    return 0;
}
