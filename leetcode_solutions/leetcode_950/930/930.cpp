#include "utils.h"

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        vi idx;
        REP(i,A.size())if(A[i])idx.pb(i);
        idx.pb(A.size());
        int cur=0;
        int ans=0;
        REP(i,A.size()){
            if(cur+S>=idx.size())break;
            ans+=idx[cur+S]-(S?idx[cur+S-1]:i);
            cur+=A[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,0,1,0,1};
    int S=2;
    auto ans=sol.numSubarraysWithSum(A,S);
    DBG(ans);

    system("pause");
    return 0;
}
