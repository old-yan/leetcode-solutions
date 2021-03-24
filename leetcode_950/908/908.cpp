#include "utils.h"

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int Min=*min_element(ALL(A)),Max=*max_element(ALL(A));
        return min(0,Max-Min-K*2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,3,6};
    int K=3;
    auto ans=sol.smallestRangeI(A,K);
    DBG(ans);

    system("pause");
    return 0;
}
