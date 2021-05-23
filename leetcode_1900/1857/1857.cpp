#include "utils.h"

class Solution {
    struct node{
        int num[26]={0};
    };
    int n;
    vi color,deg;
    vi adj[100000];
    node nn[100000];
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n=colors.size();
        REP(i,n)color[i]=colors[i]-'a';
        deg.resize(n,0);
        for(auto&e:edges){
            int i=e[0],j=e[1];
            adj[i].pb(j);
            deg[j]++;
        }
        queue<int>Q;
        REP(i,n)if(!deg[i]){
            nn[i].num[color[i]]=1;
            Q.push(i);
        }
        int ans=0;
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            REP(i,26){
                chmax(ans,nn[p].num[i]);
            }
            for(int a:adj[p]){
                REP(i,26){
                    chmax(nn[a].num[i],nn[p].num[i]+(i==color[a]));
                }
                if(!--deg[a]){
                    Q.push(a);
                }
            }
        }
        if(count(ALL(deg),0)!=deg.size())return -1;
        else return ans;
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
