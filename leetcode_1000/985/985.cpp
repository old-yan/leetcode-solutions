#include "utils.h"

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum=0;
        for(int a:A)if(a%2==0)sum+=a;
        vi ans;
        for(auto&q:queries){
            int val=q[0],idx=q[1];
            if(A[idx]%2==0)sum-=A[idx];
            A[idx]+=val;
            if(A[idx]%2==0)sum+=A[idx];
            ans.pb(sum);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,2,3,4};
    vvi queries=makevvi("[[1,0],[-3,1],[-4,0],[2,3]]");
    auto ans=sol.sumEvenAfterQueries(A,queries);
    DBGV(ans);

    system("pause");
    return 0;
}
