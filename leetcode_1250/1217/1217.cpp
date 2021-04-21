#include "utils.h"

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd=0,even=0;
        for(int p:position){
            if(p&1)odd++;
            else even++;
        }
        return min(odd,even);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi position{2,2,2,3,3};
    auto ans=sol.minCostToMoveChips(position);
    DBG(ans);

    system("pause");
    return 0;
}
