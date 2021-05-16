#include "utils.h"

class Solution {
    vi ans;
    int n,used[21]={0};
    bool dfs(int cur){
        if(cur==ans.size()){
            return true;
        }
        else if(ans[cur]){
            return dfs(cur+1);
        }
        else{
            FORR(i,n,1)if(!used[i]){
                if(i>1&&(cur+i>=ans.size()||ans[cur+i]))continue;
                used[i]=true;
                ans[cur]=i;
                if(i>1)ans[cur+i]=i;
                if(dfs(cur+1))return true;
                used[i]=false;
                ans[cur]=0;
                if(i>1)ans[cur+i]=0;
            }
            return false;
        }
    }
public:
    vector<int> constructDistancedSequence(int _n) {
        n=_n;
        ans.resize(n*2-1,0);
        dfs(0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.constructDistancedSequence(n);
    DBGV(ans);

    system("pause");
    return 0;
}
