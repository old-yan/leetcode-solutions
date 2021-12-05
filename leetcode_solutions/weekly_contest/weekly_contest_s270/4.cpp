#include "utils.h"

class Solution {
    unordered_map<int,vector<int>>adj;
    unordered_map<int,int>deg;
    vector<int>path;
    //欧拉通路模板
    void findEulerPath(int cur){
        auto&neighbors=adj[cur];
        while(neighbors.size()){
            int a=neighbors.back();
            neighbors.pop_back();
            findEulerPath(a);
        }
        path.push_back(cur);
    }
public:
    //欧拉通路模板题目
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        //建立有向图
        for(auto&pair:pairs){
            int a=pair[0],b=pair[1];
            adj[a].push_back(b);
            deg[a]--;
            deg[b]++;
        }
        int start=-1;
        //如果有结点的度为 -1，那么只能从它出发
        for(auto&it:deg){
            if(it.second==-1){
                start=it.first;
                break;
            }
        }
        //如果没有结点的度为 -1，那么可以随便从任意点出发
        if(start<0)start=deg.begin()->first;
        //使用欧拉通路模板，找出一条 path
        findEulerPath(start);
        reverse(path.begin(),path.end());
        //将 path 转换为本题的返回格式
        vector<vector<int>>ans;
        for(int i=0;i+1<path.size();i++){
            ans.push_back({path[i],path[i+1]});
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<int>>pairs=makevvi("[[5,1],[4,5],[11,9],[9,4]]");
    auto ans=sol.validArrangement(pairs);
    DBGVV(ans);

    system("pause");
    return 0;
}