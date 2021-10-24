#include "utils.h"

class Solution {
    vector<int>adj[50000];
public:
    //本题为拓扑排序的改编版本，不是按照开课顺序对后续课程解绑，而是按照结课顺序来
    //建立一个小根堆，哪门课先结课就把它的后续课程度减一，直到拓扑完成
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
        vector<int>deg(n,0);
        for(auto&r:relations){
            int a=r[0]-1,b=r[1]-1;
            adj[a].push_back(b);
            deg[b]++;
        }
        for(int i=0;i<n;i++){
            if(!deg[i])Q.emplace(time[i],i);
        }
        int ans=0;
        while(Q.size()){
            auto [t,i]=Q.top();Q.pop();
            ans=t;
            for(int a:adj[i]){
                if(!--deg[a]){
                    Q.emplace(t+time[a],a);
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    vector<vector<int>>relations=makevvi("[[1,5],[2,5],[3,5],[3,4],[4,5]]");
    vector<int>time{1,2,3,4,5};
    auto ans=sol.minimumTime(n,relations,time);
    DBG(ans);

    system("pause");
    return 0;
}