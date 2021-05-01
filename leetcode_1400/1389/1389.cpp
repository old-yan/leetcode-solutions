#include "utils.h"

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        deque<int>Q;
        REP(i,nums.size()){
            Q.insert(Q.begin()+index[i],nums[i]);
        }
        return vi(ALL(Q));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,1,2,3,4};
    vi index{0,1,2,2,1};
    auto ans=sol.createTargetArray(nums,index);
    DBGV(ans);

    system("pause");
    return 0;
}
