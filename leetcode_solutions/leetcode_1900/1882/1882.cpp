#include "utils.h"

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size(),m=tasks.size();
        queue<int>todo;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>touse;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>tofree;
        REP(i,n)touse.emplace(servers[i],i);
        vi ans(m);
        for(ll time=0;time<m||todo.size();){
            while(tofree.size()&&tofree.top().first==time){
                auto p=tofree.top().second;
                tofree.pop();
                touse.emplace(servers[p],p);
            }
            if(time<m)todo.emplace(time);
            while(todo.size()&&touse.size()){
                auto work=todo.front();
                todo.pop();
                auto use=touse.top().second;
                touse.pop();
                ans[work]=use;
                tofree.emplace(time+tasks[work],use);
            }
            if(time<m)time++;
            else if(tofree.size()&&tofree.top().first>time)time=tofree.top().first;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi servers{3,3,2};
    vi tasks{1,2,3,2,1,2};
    auto ans=sol.assignTasks(servers,tasks);
    DBGV(ans);

    system("pause");
    return 0;
}
