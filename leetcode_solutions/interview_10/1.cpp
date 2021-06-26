#include "utils.h"

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        ::merge(A.rend()-m,A.rend(),B.rend()-n,B.rend(),A.rend()-m-n,greater<int>());
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,2,3,0,0,0};
    vi B{2,5,6};
    sol.merge(A,3,B,3);
    DBGV(A);

    system("pause");
    return 0;
}
