#include "utils.h"

class Solution {
    vector<int>nums;
    int ans=0;
    void dfs(int i,int cur){
        if(i==nums.size()){
            ans^=cur;
        }
        else{
            //舍弃当前数字
            dfs(i+1,cur);
            //保留当前数字
            dfs(i+1,cur^nums[i]);
        }
    }
public:
    //dfs回溯所有可能即可
    int subsetXORSum(vector<int>& _nums) {
        nums=_nums;
        dfs(0,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,4,5,6,7,8};
    auto ans=sol.subsetXORSum(nums);
    DBG(ans);

    system("pause");
    return 0;
}
