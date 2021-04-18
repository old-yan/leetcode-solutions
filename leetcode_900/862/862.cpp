#include "utils.h"

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        partial_sum(ALL(A),A.begin());
        deque<pair<int,int>>Q{{0,-1}};
        int ans=INT_MAX;
        REP(i,A.size()){
            while(Q.size()&&Q.back().first>=A[i])Q.pop_back();
            Q.emplace_back(A[i],i);
            while(Q.size()&&A[i]-Q.front().first>=K){
                chmin(ans,int(i-Q.front().second));
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
