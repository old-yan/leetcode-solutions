#include "utils.h"

class Solution {
public:
    int minPartitions(string n) {
        return *max_element(ALL(n))-'0';
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string n="32";
    auto ans=sol.minPartitions(n);
    DBG(ans);

    system("pause");
    return 0;
}
