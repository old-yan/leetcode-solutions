#include "utils.h"

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        auto sum=presum(nums);
        int total=sum.back();
        for(int i=1;i<sum.size();i++){
            if(sum[i-1]+sum[i]==total)return i-1;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,7,3,6,5,6};
    auto ans=sol.pivotIndex(nums);
    DBG(ans);

    system("pause");
    return 0;
}
