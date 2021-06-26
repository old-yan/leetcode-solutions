#include "Union.h"
#include "utils.h"

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n=graph.size();
        sort(ALL(initial));
        int ans,ans_num=INT_MAX;
        Union u(n);
        for(int a:initial){
            u.reset();
            REP(i,n){
                REP(j,n){
                    if(i!=a&&j!=a&&graph[i][j])u.unite(i,j);
                }
            }
            bitset<300>affected;
            for(int b:initial)if(b!=a)affected.set(u.Find(b));
            int cnt=0;
            REP(i,n){
                if(affected[u.Find(i)])cnt++;
            }
            if(chmin(ans_num,cnt)){
                ans=a;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi graph=makevvi("[[1,1,0],[1,1,0],[0,0,1]]");
    vi initial{0,1};
    auto ans=sol.minMalwareSpread(graph,initial);
    DBG(ans);

    system("pause");
    return 0;
}
