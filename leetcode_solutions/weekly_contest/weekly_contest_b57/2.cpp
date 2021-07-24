#include "utils.h"

class Solution {
    struct event{
        int time;
        bool is_come;
        int id;
        bool operator<(const event&other)const{
            if(time!=other.time)return time>other.time;
            return is_come>other.is_come;
        }
    };
public:
    //模拟题，按照题意一步步处理
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        //先生成座位堆
        priority_queue<int,vector<int>,greater<int>>seats;
        for(int i=0;i<100010;i++)seats.push(i);
        
        //再生成事件堆
        priority_queue<event>Q;
        for(int i=0;i<times.size();i++){
            Q.push(event{times[i][0],true,i});
            Q.push(event{times[i][1],false,i});
        }
        
        //按照时间顺序处理事件
        int ans[times.size()];
        while(Q.size()){
            auto [time,is_come,id]=Q.top();
            Q.pop();
            if(is_come){
                ans[id]=seats.top();
                seats.pop();
            }
            else{
                seats.push(ans[id]);
            }
        }
        return ans[targetFriend];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    system("pause");
    return 0;
}
