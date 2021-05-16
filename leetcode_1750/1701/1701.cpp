#include "utils.h"

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time=0;
        double sum=0;
        for(auto&c:customers){
            time=max(time+c[1],c[0]+c[1]);
            sum+=time-c[0];
        }
        return sum/customers.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi customers=makevvi("[[1,2],[2,5],[4,3]]");
    auto ans=sol.averageWaitingTime(customers);
    DBG(ans);

    system("pause");
    return 0;
}
