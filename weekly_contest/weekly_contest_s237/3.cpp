#include "Heap.h"
#include "utils.h"

class Solution {
public:
    //按时间进度模拟
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        //将所有下标按对应的开始时间排序
        vi idx(n);
        iota(ALL(idx),0);
        sort(ALL(idx),[&](int x,int y){return tasks[x][0]<tasks[y][0];});
        //建立最小堆，运行时间短/下标小的先出堆
        Heap<int>H([&](int x,int y){
            if(tasks[x][1]!=tasks[y][1])return tasks[x][1]>tasks[y][1];
            else return x>y;
        });
        vi ans;
        ll cur=0,time=0;
        while(true){
            //马上就要接任务了，如果我目前没任务却还接不到任务，就手动快进
            if(!H.size()&&cur<n&&tasks[idx[cur]][0]>time)time=tasks[idx[cur]][0];
            //接任务
            while(cur<n&&tasks[idx[cur]][0]<=time){
                H.push(idx[cur++]);
            }
            //实在没任务就退
            if(!H.size())break;
            //有任务就选个最好的（持续时间最短/下标最小）
            int i=H.top();
            H.pop();
            ans.pb(i);
            time+=tasks[i][1];
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
