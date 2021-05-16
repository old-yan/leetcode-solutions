#include "utils.h"

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>Q;
        for(int time=0;time<apples.size()||Q.size();time++){
            if(time<apples.size()&&apples[time])Q.emplace(time+days[time],apples[time]);
            while(Q.size()&&Q.top().first<=time)Q.pop();
            if(Q.size()){
                auto p=Q.top();
                Q.pop();
                if(--p.second)Q.push(p);
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi apples{1,2,3,5,2};
    vi days{3,2,1,4,2};
    auto ans=sol.eatenApples(apples,days);
    DBG(ans);

    system("pause");
    return 0;
}
