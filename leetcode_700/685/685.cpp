#include "Tarjan.h"
#include "utils.h"

class Solution {
    void init(vvi&edges){
        for(auto&edge:edges){edge[0]--,edge[1]--;}
    }
    void topologicalSort(vvi&edges,vi&deg,int head,vector<bool>&visited){
        vi v[edges.size()];
        for(auto&edge:edges)v[edge[0]].pb(edge[1]);
        queue<int>Q;
        Q.push(head);
        while(Q.size()){
            auto p=Q.front();
            visited[p]=true;
            Q.pop();
            for(int child:v[p]){
                if(!--deg[child])Q.push(child);
            }
        }
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        init(edges);
        int n=edges.size();
        vi deg(n,0);
        for(auto&edge:edges)deg[edge[1]]++;
        if(find(deg.begin(),deg.end(),0)!=deg.end()){
            int zero_deg=find_if(deg.begin(),deg.end(),[](int x){return x==0;})-deg.begin();
            int twodeg=find_if(ALL(deg),[](int x){return x==2;})-deg.begin();
            int firstfrom=(*find_if(ALL(edges),[&](vector<int>&x){return x[1]==twodeg;}))[0];
            int secondfrom=(*find_if(ALLR(edges),[&](vector<int>&x){return x[1]==twodeg;}))[0];
            vector<bool>visited(n,false);
            topologicalSort(edges,deg,zero_deg,visited);
            if(visited[firstfrom])return {secondfrom+1,twodeg+1};
            else return {firstfrom+1,twodeg+1};
        }
        else{
            vi color(n,-1);
            tarjanSCC(ALL(edges),&color[0]).findSCC();
            auto last_on_cycle=*find_if(ALLR(edges),[&](vi&x){return color[x[0]]==color[x[1]];});
            last_on_cycle[0]++,last_on_cycle[1]++;
            return last_on_cycle;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi edges{
        {1,2},{2,3},{3,4},{4,1},{1,5}
    };
    auto ans=sol.findRedundantDirectedConnection(edges);
    DBGV(ans);

    system("pause");
    return 0;
}
