#include "TreeNode.h"
#include "utils.h"

class Solution {
    TreeNode*makenode(int h,int t,vi&nums){
        if(h>t)return nullptr;
        int mid=(h+t)/2;
        return new TreeNode(nums[mid],makenode(h,mid-1,nums),makenode(mid+1,t,nums));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makenode(0,nums.size()-1,nums);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{-10,-3,0,5,9};
    auto ans=sol.sortedArrayToBST(nums);
    DBG(ans);

    system("pause");
    return 0;
}
