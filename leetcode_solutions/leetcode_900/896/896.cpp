#include "utils.h"

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        return is_sorted(ALL(A))||is_sorted(ALL(A),greater<int>());
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,2,2,3};
    auto ans=sol.isMonotonic(A);
    DBG(ans);

    system("pause");
    return 0;
}
