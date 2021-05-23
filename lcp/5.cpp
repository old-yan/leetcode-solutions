#include "utils.h"

class Solution {
public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {

    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=6;
    vvi leadership=makevvi("[[1, 2], [1, 6], [2, 3], [2, 5], [1, 4]]");
    vvi operations=makevvi("[[1, 1, 500], [2, 2, 50], [3, 1], [2, 6, 15], [3, 1]]");
    auto ans=sol.bonus(n,leadership,operations);
    DBGV(ans);

    system("pause");
    return 0;
}
