#include "Graph.h"
#include "utils.h"

class Solution {
    struct node{
        int num[26]={0};
    }nn[100000];
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        dg.reset(n);
        for(auto&e:edges){
            int i=e[0],j=e[1];
            dg.addEdge(i,j);
        }
        tp.solve(dg);
        if(tp.seq.size()<n)return -1;
        int ans=0;
        for(int a:tp.seq){
            nn[a].num[colors[a]-'a']++;
            REP(i,26)chmax(ans,nn[a].num[i]);
            for(int _=dg.fi[a];~_;_=dg.ne[_]){
                int j=dg.to[_];
                REP(i,26)chmax(nn[j].num[i],nn[a].num[i]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string color="abaca";
    vvi edges=makevvi("[[0,1],[0,2],[2,3],[3,4]]");
    auto ans=sol.largestPathValue(color,edges);
    DBG(ans);

    system("pause");
    return 0;
}
