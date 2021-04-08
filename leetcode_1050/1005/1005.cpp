#include "utils.h"

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int sum=accumulate(ALL(A),0);
        priority_queue<int,vi,greater<int>>Q;
        for(int a:A)Q.push(a);
        while(K--){
            auto p=Q.top();
            Q.pop();
            sum-=p*2;
            Q.push(-p);
        }
        return sum;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{2,-3,-1,5,-4};
    int K=2;
    auto ans=sol.largestSumAfterKNegations(A,K);
    DBG(ans);

    system("pause");
    return 0;
}
