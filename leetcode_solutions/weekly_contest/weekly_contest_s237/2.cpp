#include "utils.h"

class Solution {
public:
    //贪心，从最小的开始取
    int maxIceCream(vector<int>& costs, int coins) {
        sort(ALL(costs));
        int ans=0;
        for(int a:costs){
            if(coins>=a){
                coins-=a;
                ans++;
            }
            else break;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi costs{1,6,3,1,2,5};
    int coins=20;
    auto ans=sol.maxIceCream(costs,coins);
    DBG(ans);

    system("pause");
    return 0;
}
