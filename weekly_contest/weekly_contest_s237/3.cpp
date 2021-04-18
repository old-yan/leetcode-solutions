#include "utils.h"

class Solution {
    typedef pair<int,int> PII;
public:
    //按时间进度模拟
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        //将所有下标按对应的开始时间排序
        vi idx(n);
        iota(ALL(idx),0);
        sort(ALL(idx),[&](int x,int y){return tasks[x][0]<tasks[y][0];});
        //建立最小堆，运行时间短/下标小的先出堆
        priority_queue<PII,vector<PII>,greater<PII>>Q;
        vi ans;
        for(ll t=tasks[idx[0]][0],cursor=0;cursor<n||Q.size();){
            while(cursor<n&&tasks[idx[cursor]][0]<=t){
                Q.emplace(tasks[idx[cursor]][1],idx[cursor]);
                cursor++;
            }
            //一次循环处理一个任务
            auto [last,i]=Q.top();
            Q.pop();
            ans.pb(i);
            t+=last;
            //为了避免青黄不接，如果现在接不到任务，那就让时间往后流一流
            if(cursor<n&&Q.empty()&&tasks[idx[cursor]][0]>t)t=tasks[idx[cursor]][0];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi tasks=makevvi("[[7,10],[7,12],[7,5],[7,4],[7,2]]");
    auto ans=sol.getOrder(tasks);
    DBGV(ans);

    system("pause");
    return 0;
}
