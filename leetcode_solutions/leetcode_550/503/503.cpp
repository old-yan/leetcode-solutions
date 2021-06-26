#include "utils.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>S;
        vi ans(nums.size());
        REPR(i,nums.size()-1){
            while(S.size()&&S.top()<=nums[i])S.pop();
            S.push(nums[i]);
        }
        REPR(i,nums.size()-1){
            while(S.size()&&S.top()<=nums[i])S.pop();
            ans[i]=S.size()?S.top():-1;
            S.push(nums[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,1};
    auto ans=sol.nextGreaterElements(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
