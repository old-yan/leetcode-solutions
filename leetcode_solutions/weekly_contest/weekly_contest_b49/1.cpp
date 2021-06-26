#include "utils.h"

class Solution {
public:
    //经过观察，可以对第一个字符和第二个字符模2的余值进行比较得出结果
    bool squareIsWhite(string coordinates) {
        return (coordinates[0]-'a')%2==(coordinates[1]-'0')%2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string coordinates="c7";
    auto ans=sol.squareIsWhite(coordinates);
    DBG(ans);

    system("pause");
    return 0;
}
