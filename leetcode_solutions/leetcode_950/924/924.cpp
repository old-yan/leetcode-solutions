#include "Union.h"
#include "utils.h"

class Solution {
    int cnt[300]={0};
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n=graph.size();
        Union u(n);
        REP(i,n){
            REP(j,n){
                if(graph[i][j])u.unite(i,j);
            }
        }
        sort(ALL(initial));
        for(int a:initial)cnt[u.Find(a)]++;
        int ans,ans_num=-1;
        for(int a:initial){
            int num=cnt[u.Find(a)]==1?u.size[u.Find(a)]:0;
            if(chmax(ans_num,num)){
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
