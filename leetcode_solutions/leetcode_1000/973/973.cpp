#include "utils.h"

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi points=makevvi("[[1,3],[-2,2]]");
    int K=1;
    auto ans=sol.kClosest(points,K);
    DBGVV(ans);

    system("pause");
    return 0;
}
