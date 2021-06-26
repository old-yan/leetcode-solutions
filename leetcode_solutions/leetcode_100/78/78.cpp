#include "utils.h"

class Solution {
    vvi ans;
    int path[20];
    void dfs(int idx,int i,vi&nums){
        if(i==nums.size()){
            ans.pb(vi(path,path+idx));
        }
        else{
            dfs(idx,i+1,nums);
            path[idx++]=nums[i];
            dfs(idx,i+1,nums);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,0,nums);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3};
    auto ans=sol.subsets(nums);
    DBGVV(ans);

    system("pause");
    return 0;
}
