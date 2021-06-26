#include "utils.h"

class Solution {
public:
    int multiply(int A, int B) {
        if(A>B)swap(A,B);
        if(A==0)return 0;
        else return multiply(A-1,B)+B;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int A=3;
    int B=4;
    auto ans=sol.multiply(A,B);
    DBG(ans);

    system("pause");
    return 0;
}
