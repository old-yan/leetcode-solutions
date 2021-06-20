#include "utils.h"

class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        auto&a=numbers[0];
        auto&b=numbers[1];
        a^=b;
        b^=a;
        a^=b;
        return {a,b};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi numbers{1,2};
    auto ans=sol.swapNumbers(numbers);
    DBGV(ans);

    system("pause");
    return 0;
}
