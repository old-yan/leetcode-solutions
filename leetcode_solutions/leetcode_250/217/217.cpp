#include "utils.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>S;
        for(int a:nums){
            if(S.count(a))return true;
            S.insert(a);
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,1};
    auto ans=sol.containsDuplicate(nums);
    DBG(ans);

    system("pause");
    return 0;
}
