#include "utils.h"

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles,empty=numBottles;
        while(empty>=numExchange){
            ans+=empty/numExchange;
            empty=empty%numExchange+empty/numExchange;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int numBottles=9;
    int numExchange=3;
    auto ans=sol.numWaterBottles(numBottles,numExchange);
    DBG(ans);

    system("pause");
    return 0;
}
