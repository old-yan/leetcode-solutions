#include "utils.h"

class Solution {
    vvi ans;
    int l;
    void dfs(int i,int path[]){
        if(i==l)ans.pb(vi(path,path+l));
        else{
            FOR(j,i,l){
                swap(path[i],path[j]);
                dfs(i+1,path);
                swap(path[i],path[j]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        l=nums.size();
        int path[l];
        memcpy(path,&nums[0],sizeof(path));
        dfs(0,path);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3};
    auto ans=sol.permute(nums);
    DBGVV(ans);

    system("pause");
    return 0;
}
