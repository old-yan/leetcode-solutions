#include "utils.h"

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        //使用一个队列存储待做的任务
        queue<int>todo;
        auto comp=[&](int x,int y){
            if(servers[x]!=servers[y])return servers[x]>servers[y];
            else return x>y;
        };
        //使用一个优先级队列存储空闲的服务器
        priority_queue<int,vi,decltype(comp)>idle(comp);
        int n=servers.size(),m=tasks.size();
        vi ans(m);
        //所有服务器待命
        REP(i,n)idle.push(i);
        //使用一个map保存每个时间点要释放的服务器
        map<int,vi>tofree;
        REP(time,m){
            //先释放服务器
            if(tofree.count(time)){
                for(int a:tofree[time])idle.push(a);
                tofree.erase(time);
            }
            //填充任务队列
            todo.push(time);
            //如果有任务也有服务器，那就配对
            while(todo.size()&&idle.size()){
                auto work=todo.front();
                todo.pop();
                auto server=idle.top();
                idle.pop();
                ans[work]=server;
                tofree[tasks[work]+time].pb(server);
            }
        }
        //时间到了m之后，还有可能有任务积压，恰好tofree的迭代器是按时间递增的，遍历tofree，边释放服务器边解决挤压任务
        for(auto it=tofree.begin();it!=tofree.end();it++){
            int time=it->first;
            //先释放服务器
            for(int server:it->second)idle.push(server);
            while(todo.size()&&idle.size()){
                auto work=todo.front();
                todo.pop();
                auto server=idle.top();
                idle.pop();
                ans[work]=server;
                tofree[tasks[work]+time].pb(server);
            }
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
