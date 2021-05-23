#include "utils.h"

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>work;
        REP(i,n){
            work.emplace(tasks[i][0],tasks[i][1],i);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>can;
        ll time=0;
        vi ans;
        while(true){
            if(can.empty()&&work.size()){
                chmax(time,(ll)get<0>(work.top()));
            }
            while(work.size()&&get<0>(work.top())<=time){
                auto [t1,t2,i]=work.top();
                work.pop();
                can.emplace(t2,i);
            }
            if(can.empty())break;
            auto [t2,i]=can.top();
            can.pop();
            ans.pb(i);
            time+-t2;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi tasks=makevvi("[[1,2],[2,4],[3,2],[4,1]]");
    auto ans=sol.getOrder(tasks);
    DBGV(ans);

    system("pause");
    return 0;
}
