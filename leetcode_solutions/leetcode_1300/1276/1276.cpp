#include "utils.h"

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int c=tomatoSlices-cheeseSlices*2;
        if(c<0||c%2||c>cheeseSlices*2)return {};
        int x=c/2;
        int y=cheeseSlices-x;
        return {x,y};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int tomatoSlices=16;
    int cheeseSlices=7;
    auto ans=sol.numOfBurgers(tomatoSlices,cheeseSlices);
    DBGV(ans);

    system("pause");
    return 0;
}
