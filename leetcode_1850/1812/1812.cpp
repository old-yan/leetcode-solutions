#include "utils.h"

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return coordinates[0]%2!=coordinates[1]%2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string coordinates="a1";
    auto ans=sol.squareIsWhite(coordinates);
    DBG(ans);

    system("pause");
    return 0;
}
