#include "Tarjan.h"
#include "utils.h"

class Solution {
public:
    //拓扑排序判断能否成环，同时按照拓扑排序的顺序进行动态规划：
    //后继点的最大颜色值，建立在前驱点的基础之上
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size(),m=edges.size();
        vi deg(n,0),adj[n];
        int cnt[n][26];
        memset(cnt,0,sizeof(cnt));
        for(auto&e:edges){
            int i=e[0],j=e[1];
            adj[i].pb(j);
            deg[j]++;
        }
        //拓扑排序就是不断访问入度为0的结点，访问的时候给它的后继结点入度减一
        queue<int>Q;
        REP(i,n)if(!deg[i]){
            Q.push(i);
            cnt[i][colors[i]-'a']++;
        }
        int ans=0,visit=0;
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            visit++;
            chmax(ans,*max_element(cnt[p],cnt[p]+26));
            //用前驱的各种颜色数，优化后继的各种颜色数
            for(int a:adj[p]){
                REP(i,26)chmax(cnt[a][i],cnt[p][i]+(i==colors[a]-'a'));
                if(!--deg[a])Q.push(a);
            }
        }
        return visit==n?ans:-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string colors="abaca";
    vvi edges=makevvi("[[0,1],[0,2],[2,3],[3,4]]");
    auto ans=sol.largestPathValue(colors,edges);
    DBG(ans);

    system("pause");
    return 0;
}
