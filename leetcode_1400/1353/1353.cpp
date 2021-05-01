#include "utils.h"

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(ALL(events));
        priority_queue<int,vi,greater<int>>Q;
        int ans=0;
        for(int i=0;i<events.size();){
            int cur=events[i][0];
            while(i<events.size()&&events[i][0]==cur){
                Q.push(events[i++][1]);
            }
            int next=i==events.size()?INT_MAX:events[i][0];
            while(cur<next){
                while(Q.size()&&Q.top()<cur)Q.pop();
                if(Q.size()){
                    Q.pop();
                    ans++;
                    cur++;
                }
                else break;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi events=makevvi("[[1,2],[2,3],[3,4]]");
    auto ans=sol.maxEvents(events);
    DBG(ans);

    system("pause");
    return 0;
}
