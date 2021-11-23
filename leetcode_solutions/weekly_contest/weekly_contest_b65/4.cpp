#include "utils.h"

class Solution {
public:
    //二分判断可行性
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.rbegin(),workers.rend());
        auto check=[&](int k){
            // Q 中保存所有可能完成任务的工人，而且为单调队列，队首的较大，队尾的较小
            deque<int>Q;
            int cursor=0;
            int rest_pill=pills;
            for(int i=k-1;i>=0;i--){
                int task=tasks[i];
                //先扩充队列
                while(cursor<workers.size() and workers[cursor]+strength>=task)
                    Q.emplace_back(workers[cursor++]);
                //没有可选工人，失败
                if(Q.empty())return false;
                //队首工人不需要吃药，那就他来
                if(Q.front()>=task){
                    Q.pop_front();
                }
                //队首工人也需要吃药，那就让队尾来吃药，反正吃了药都能完成，不如把队首留下
                else if(rest_pill){
                    Q.pop_back();
                    rest_pill--;
                }
                //没药了就失败了
                else return false;
            }
            return true;
        };
        int low=0,high=min(tasks.size(),workers.size());
        while(low<high){
            int mid=(low+high+1)/2;
            if(check(mid))low=mid;
            else high=mid-1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>tasks{3,2,1};
    vector<int>workers{0,3,3};
    int pills=1;
    int strength=1;
    auto ans=sol.maxTaskAssign(tasks,workers,pills,strength);
    DBG(ans);

    system("paused");
    return 0;
}