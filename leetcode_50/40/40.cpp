#include "utils.h"

class Solution {
    vi candidates;
    vi next;
    int path[10000];
    vvi ans;
    void dfs(int i,int idx,int rest){
        if(i==candidates.size()){
            if(!rest)ans.pb(vi(path,path+idx));
        }
        else{
            dfs(next[i],idx,rest);
            if(rest>=candidates[i]){
                path[idx]=candidates[i];
                dfs(i+1,idx+1,rest-candidates[i]);
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& _candidates, int target) {
        candidates=_candidates;
        sort(ALL(candidates));
        next=next_different(candidates);
        dfs(0,0,target);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi candidates{10,1,2,7,6,1,5};
    int target=8;
    auto ans=sol.combinationSum2(candidates,target);
    DBGVV(ans);

    system("pause");
    return 0;
}
