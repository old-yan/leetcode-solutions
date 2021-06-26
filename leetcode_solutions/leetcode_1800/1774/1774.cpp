#include "utils.h"

class Solution {
    vi toppingCosts;
    vi v;
    void dfs(int i,int cur){
        if(i==toppingCosts.size()){
            v.pb(cur);
        }
        else{
            dfs(i+1,cur);
            dfs(i+1,cur+toppingCosts[i]);
            dfs(i+1,cur+toppingCosts[i]*2);
        }
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& _toppingCosts, int target) {
        auto closer=[](int a,int b,int target){
            if(abs(a-target)!=abs(b-target))return abs(a-target)<abs(b-target);
            else return a<b;
        };
        toppingCosts=_toppingCosts;
        dfs(0,0);
        int ans=baseCosts[0];
        for(int a:v){
            for(int b:baseCosts){
                if(closer(a+b,ans,target)){
                    ans=a+b;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi baseCosts{1,7};
    vi toppingCosts{3,4};
    int target=10;
    auto ans=sol.closestCost(baseCosts,toppingCosts,target);
    DBG(ans);

    system("pause");
    return 0;
}
