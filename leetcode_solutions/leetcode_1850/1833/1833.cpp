#include "utils.h"

class Solution {
public:
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

    vi costs{1,3,2,4,1};
    int coins=7;
    auto ans=sol.maxIceCream(costs,coins);
    DBG(ans);

    system("pause");
    return 0;
}
