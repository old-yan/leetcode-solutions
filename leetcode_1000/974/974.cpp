#include "utils.h"

class Solution {
    int num[10000]={0};
public:
    int subarraysDivByK(vector<int>& A, int K) {
        for(int&a:A)a+=10000*K;
        auto sum=presum(A);
        int ans=0;
        for(ll a:sum){
            a%=K;
            ans+=num[a]++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{4,5,0,-2,-3,1};
    int K=5;
    auto ans=sol.subarraysDivByK(A,K);
    DBG(ans);

    system("pause");
    return 0;
}
