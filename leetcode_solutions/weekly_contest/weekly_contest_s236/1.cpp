#include "utils.h"

class Solution {
public:
    //先数0，再数负数
    int arraySign(vector<int>& nums) {
        for(int a:nums){
            if(!a)return 0;
        }
        int negative=0;
        for(int a:nums){
            if(a<0)negative++;
        }
        return negative%2?-1:1;
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
