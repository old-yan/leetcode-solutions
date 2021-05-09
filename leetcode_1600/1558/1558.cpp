#include "utils.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int move=0,add=0;
        for(int a:nums){
            if(a)chmax(move,31-__builtin_clz(a));
            add+=__builtin_popcount(a);
        }
        return add+move;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4,2,5};
    auto ans=sol.minOperations(nums);
    DBG(ans);

    system("pause");
    return 0;
}
