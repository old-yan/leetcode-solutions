#include "utils.h"

class Solution {
    vi nums;
    vvi ans;
    vi path;
    void dfs(int cur){
        path.pb(nums[cur]);
        if(path.size()>1)ans.pb(path);
        bool visited[300]={0};
        FOR(i,cur+1,nums.size()){
            if(nums[i]>=nums[cur]){
                if(visited[nums[i]+100])continue;
                dfs(i);
                visited[nums[i]+100]=true;
            }
        }
        path.pop_back();
    }
public:
    vector<vector<int>> findSubsequences(vector<int>&_nums) {
        nums=_nums;
        bool visited[300]={0};
        REP(i,nums.size()){
            if(visited[nums[i]+100])continue;
            dfs(i);
            visited[nums[i]+100]=true;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{4,6,7,7};
    auto ans=sol.findSubsequences(nums);
    DBGVV(ans);

    system("pause");
    return 0;
}
