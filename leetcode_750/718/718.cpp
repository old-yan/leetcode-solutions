#include "utils.h"



int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,2,3,2,1};
    vi B{3,2,1,4,7};
    auto ans=sol.findLength(A,B);

    system("pause");
    return 0;
}
