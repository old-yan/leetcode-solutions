#include "utils.h"

class Solution {
    bool visited[1<<12][12];
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<tuple<int,int,int>>Q;
        REP(i,n){
            for(int j:graph[i]){
                visited[(1<<i)+(1<<j)][i]=true;
                Q.emplace((1<<i)+(1<<j),i,1);
            }
        }
        while(Q.size()){
            auto [state,i,step]=Q.front();
            Q.pop();
            if(state==(1<<n)-1)return step;
            for(int j:graph[i]){
                if(!visited[(state|(1<<j))][j]){
                    visited[(state|(1<<j))][j]=true;
                    Q.emplace(state|(1<<j),j,step+1);
                }
            }
        }
        return 0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi graph=makevvi("[[1,2,3],[0],[0],[0]]");
    auto ans=sol.shortestPathLength(graph);
    DBG(ans);

    system("pause");
    return 0;
}
