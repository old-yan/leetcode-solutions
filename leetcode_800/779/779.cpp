#include "utils.h"

class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N==1)return 0;
        else if(K%2)return kthGrammar(N-1,(K+1)/2);
        else return !kthGrammar(N-1,(K+1)/2);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=4;
    int K=5;
    auto ans=sol.kthGrammar(N,K);
    DBG(ans);

    system("pause");
    return 0;
}
