#include "utils.h"

class Solution {
public:
    int minCount(vector<int>& coins) {
        int sum=0;
        for(int a:coins){
            sum+=ceil(double(a)/2);
        }
        return sum;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi coins{4,2,1};
    auto ans=sol.minCount(coins);
    DBG(ans);

    system("pause");
    return 0;
}
