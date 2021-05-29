#include "SegTree.h"
#include "utils.h"

LazyTree<int,0,1>T(50001,[](int x,int y){return (x+y)%MOD;});
class Solution {
    vi sons[50001];
    int left[50001],right[50001],cnt=0;
    void dfs(int cur){
        left[cur]=cnt++;
        for(int a:sons[cur]){
            dfs(a);
        }
        right[cur]=cnt-1;
    }
public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        ll sum=0;
        int p[50001];
        for(auto&l:leadership){
            sons[l[0]].pb(l[1]);
            p[l[1]]=l[0];
            sum+=l[1];
        }

        int root=(ll)n*(n+1)/2-sum;
        dfs(root);
        T.set(0);
        vi ans;
        for(auto&op:operations){
            if(op[0]==1){
                T.step(left[op[1]],op[2]);
            }
            else if(op[0]==2){
                T.step(left[op[1]],right[op[1]],op[2]);
            }
            else{
                auto res=T(left[op[1]],right[op[1]]);
                ans.pb(res);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=6;
    vvi leadership=makevvi("[[1, 2], [1, 6], [2, 3], [2, 5], [1, 4]]");
    vvi operations=makevvi("[[1, 1, 500], [2, 2, 50], [3, 1], [2, 6, 15], [3, 1]]");
    auto ans=sol.bonus(n,leadership,operations);
    DBGV(ans);

    system("pause");
    return 0;
}
