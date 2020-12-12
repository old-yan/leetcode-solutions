#include "utils.h"

class Solution {
    int l;
    vvi ans;
    unordered_map<int,int>M;
    void dfs(int i,int path[]){
        if(i==l)ans.pb(vi(path,path+l));
        else{
            for(auto&it:M){
                if(it.second){
                    it.second--;
                    path[i]=it.first;
                    dfs(i+1,path);
                    it.second++;
                }
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        l=nums.size();
        int path[l];
        for(int a:nums)M[a]++;
        dfs(0,path);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,1,2};
    auto ans=sol.permuteUnique(nums);
    DBGVV(ans);

    system("pause");
    return 0;
}
