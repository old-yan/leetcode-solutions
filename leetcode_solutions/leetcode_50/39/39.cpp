#include "utils.h"

class Solution {
    vi candidates;
    vvi ans;
    int path[30];
    void dfs(int i,int idx,int rest){
        if(i==candidates.size()){
            if(!rest)ans.pb(vi(path,path+idx));
        }
        else{
            dfs(i+1,idx,rest);
            for(int j=1;(rest-=candidates[i])>=0;j++){
                path[idx+j-1]=candidates[i];
                dfs(i+1,idx+j,rest);
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& _candidates, int target) {
        candidates=_candidates;
        sort(ALL(candidates));
        dfs(0,0,target);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi candidates{2,3,6,7};
    int target=7;
    auto ans=sol.combinationSum(candidates,target);
    DBGVV(ans);

    system("pause");
    return 0;
}
