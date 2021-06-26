#include "utils.h"

class Solution {
    int num[10000]={0};
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int d=20000-20000%K;
        for(int&a:A)a+=d;
        partial_sum(ALL(A),A.begin());
        int ans=0;
        num[0]++;
        for(ll a:A){
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
