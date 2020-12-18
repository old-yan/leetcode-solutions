#include "utils.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        REP(i,n)gas[i]-=cost[i];
        vi _presum=presum(gas);
        if(_presum.back()<0)return -1;
        int lowest=0;
        REP(i,n){
            if(_presum[i+1]<_presum[lowest])lowest=i+1;
        }
        return lowest%n;
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
