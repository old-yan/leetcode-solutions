#include "utils.h"

class Solution {
    struct event{
        int time;
        bool is_come;
        int color;
        bool operator<(const event&other)const{
            if(time!=other.time)return time>other.time;
            return is_come>other.is_come;
        }
    };
public:
    //和上一题一样是一道模拟题
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {        
        //把所有事件放到事件堆里去
        priority_queue<event>Q;
        for(int i=0;i<segments.size();i++){
            int start=segments[i][0],end=segments[i][1],color=segments[i][2];
            Q.push(event{start,true,color});
            Q.push(event{end,false,color});
        }
        
        //按照时间顺序遍历
        long long curstate=0;
        long long prestate=0,pretime;
        vector<vector<long long>> ans;
        while(Q.size()){
            auto [time,is_come,color]=Q.top();
            Q.pop();
            if(is_come){
                curstate+=color;
            }
            else{
                curstate-=color;
            }
            if(prestate && time!=pretime){
                ans.push_back({pretime,time,prestate});
            }
            pretime=time,prestate=curstate;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string num="?3295???";
    auto ans=sol.sumGame(num);
    DBG(ans);

    system("pause");
    return 0;
}
