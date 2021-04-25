#include "utils.h"

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int a:nums){
            if(int(log10(a))%2)ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{555,901,482,1771};
    auto ans=sol.findNumbers(nums);
    DBG(ans);

    system("pause");
    return 0;
}
