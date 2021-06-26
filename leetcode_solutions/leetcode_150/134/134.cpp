#include "utils.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        REP(i,n)gas[i]-=cost[i];
        partial_sum(ALL(gas),gas.begin());
        if(gas.back()<0)return -1;
        return (min_element(ALL(gas))-gas.begin()+1)%n;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi gas{5,8,2,8};
    vi cost{6,5,6,6};
    auto ans=sol.canCompleteCircuit(gas,cost);
    DBG(ans);

    system("pause");
    return 0;
}
