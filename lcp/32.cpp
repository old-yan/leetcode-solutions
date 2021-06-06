#include "utils.h"

class Solution {
    vi times;
    void init(vvi&tasks){
        sort(ALL(tasks));
        for(auto&t:tasks){
            times.pb(t[0]);
            times.pb(t[1]+1);
        }
        sort(ALL(times));
        times.resize(unique(ALL(times))-times.begin());
    }
public:
    int processTasks(vector<vector<int>>& tasks) {
        init(tasks);
        typedef tuple<int,int,int> tii;
        priority_queue<tii,vector<tii>,greater<tii>>todeal,todo;
        REP(i,tasks.size())todo.emplace(tasks[i][0],tasks[i][1]+1,tasks[i][2]);
        int work=0,nowork=0;
        REP(i,times.size()){
            while(todeal.size()){
                auto [idle,end,need]=todeal.top();
                if(need-work<=0)todeal.pop();
                else{
                    int cur=max(0,need-work-(end-times[i]));
                    work+=cur;
                    nowork+=times[i]-times[i-1]-cur;
                    break;
                }
            }
            while(todo.size()){
                auto [start,end,need]=todo.top();
                if(start!=times[i])break;
                todo.pop();
                todeal.emplace(nowork+end-start-need,end,need+work);
            }
        }
        return work;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi tasks=makevvi("[[1,3,2],[2,5,3],[5,6,2]]");
    auto ans=sol.processTasks(tasks);
    DBG(ans);

    system("pause");
    return 0;
}
