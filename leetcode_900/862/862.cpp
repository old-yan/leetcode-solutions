#include "utils.h"

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        auto sum=presum(A);
        deque<int>Q{0};
        int ans=INT_MAX;
        FOR(i,1,sum.size()){
            while(Q.size()&&sum[Q.back()]>=sum[i])Q.pop_back();
            Q.push_back(i);
            while(Q.size()&&sum[i]-sum[Q.front()]>=K){
                chmin(ans,int(i-Q.front()));
                Q.pop_front();
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};


int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{2,-1,2};
    int K=3;
    auto ans=sol.shortestSubarray(A,K);
    DBG(ans);

    system("pause");
    return 0;
}
