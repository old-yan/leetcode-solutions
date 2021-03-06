#include "utils.h"

class Solution {
    vvi ans;
    void traverse(int cur,vi&path,vvi&graph){
        path.pb(cur);
        if(cur==graph.size()-1)ans.pb(path);
        else{
            for(auto&a:graph[cur]){
                traverse(a,path,graph);
            }
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vi path;
        traverse(0,path,graph);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi graph=makevvi("[[1,2],[3],[3],[]]");
    auto ans=sol.allPathsSourceTarget(graph);
    DBGVV(ans);

    system("pause");
    return 0;
}
