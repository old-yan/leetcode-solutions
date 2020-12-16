#include "utils.h"

class Solution {
    vvi ans{{}};
    vi nums;
    vi next;
    int path[20];
    void dfs(int i,int idx){
        path[idx++]=nums[i];
        ans.pb(vi(path,path+idx));
        for(int j=i+1;j<nums.size();j=next[j]){
            dfs(j,idx);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>&_nums) {
        nums=_nums;
        sort(ALL(nums));
        next=next_different(nums);
        for(int i=0;i<nums.size();i=next[i]){
            dfs(i,0);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,2};
    auto ans=sol.subsetsWithDup(nums);
    DBGVV(ans);

    system("pause");
    return 0;
}
