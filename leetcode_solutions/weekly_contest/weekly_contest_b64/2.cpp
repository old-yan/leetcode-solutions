#include "utils.h"

class Solution {
public:
    //我们可以枚举 second event，寻找其能配对的 first event 最大价值
    //对于一个 second event ，它能配对的 first event 的可选条件是：
    //  first event.end<second event.start
    //显然我们可以将 events 按照 end 属性排序，first event的可选范围就是 events 的一个前缀区间
    //这样，本题就转化为前缀最大值问题
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[](auto&x,auto&y){
            return x[1]<y[1];
        });
        //前缀最大值
        vector<int>premax{0};
        for(auto&e:events){
            premax.push_back(max(premax.back(),e[2]));
        }
        int ans=0;
        //枚举第二个event
        for(auto&second:events){
            int start=second[0];
            int value=second[2];
            //找出第一个event的范围
            int first_event_range;
            {
                //二分找出 low 为第一个不能和 second 配对的下标
                //那么显然 events[0~low-1] 可以充当 first_event
                int low=0,high=events.size();
                while(low<high){
                    int mid=low+high>>1;
                    if(events[mid][1]>=start)high=mid;
                    else low=mid+1;
                }
                first_event_range=low-1;
            }
            //利用做好的前缀最大值来更新答案
            ans=max(ans,value+premax[first_event_range+1]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<int>>events=makevvi("[[1,3,2],[4,5,2],[2,4,3]]");
    auto ans=sol.maxTwoEvents(events);
    DBG(ans);

    system("pause");
    return 0;
}