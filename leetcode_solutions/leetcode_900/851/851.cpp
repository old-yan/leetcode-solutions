#include "utils.h"

class Solution {
    int deg[500]={0};
    vi adj[500];
    bitset<500>b[500];
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        for(auto&r:richer){
            int i=r[0],j=r[1];
            deg[j]++;
            adj[i].pb(j);
        }
        queue<int>Q;
        REP(i,n)if(!deg[i])Q.push(i);
        while(Q.size()){
            auto p=Q.front();
            b[p].set(p);
            Q.pop();
            for(int a:adj[p]){
                b[a]|=b[p];
                if(!--deg[a]){
                    Q.push(a);
                }
            }
        }
        vi ans(n);
        REP(i,n){
            auto quieter=[&](int x,int y){
                return quiet[x]<quiet[y];
            };
            ans[i]=b[i]._Find_first();
            int j=ans[i];
            while((j=b[i]._Find_next(j))<500){
                if(quieter(j,ans[i]))ans[i]=j;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi richer=makevvi("[[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]");
    vi quiet{3,2,5,4,6,1,7,0};
    auto ans=sol.loudAndRich(richer,quiet);
    DBGV(ans);

    system("pause");
    return 0;
}
