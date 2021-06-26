#include "utils.h"

class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        if(j==31)return (N%(1<<i))+(M<<i);
        else return (N>>(j+1)<<(j+1))+(N%(1<<i))+(M<<i);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=1024;
    int M=19;
    int i=2;
    int j=6;
    auto ans=sol.insertBits(N,M,i,j);
    DBG(ans);

    system("pause");
    return 0;
}
