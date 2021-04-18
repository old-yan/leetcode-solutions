#include "utils.h"

class Solution {
public:
    //维护之前值，逐个遍历数组，将当前值改得比之前值大
    int minOperations(vector<int>& nums) {
        int pre=INT_MIN;
        int ans=0;
        for(int a:nums){
            if(a<=pre){
                ans+=pre+1-a;
                a=pre+1;
                pre++;
            }
            else pre=a;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,5,2,4,1};
    auto ans=sol.minOperations(nums);
    DBG(ans);

    system("pause");
    return 0;
}
