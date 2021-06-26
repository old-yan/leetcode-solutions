#include "utils.h"

class Solution {
    vvi ans;
    int path[100],l=0;
    void dfs(int cur,vi&nums){
        if(cur==nums.size()){
            ans.emplace_back(path,path+l);
        }
        else{
            dfs(cur+1,nums);
            path[l++]=nums[cur];
            dfs(cur+1,nums);
            l--;
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3};
    auto ans=sol.subsets(nums);
    DBG(ans);

    system("pause");
    return 0;
}
