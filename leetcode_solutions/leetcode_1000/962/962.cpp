#include "utils.h"

int idx[50000];
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n=A.size();
        iota(idx,idx+n,0);
        sort(idx,idx+n,[&](int x,int y){
            return A[x]<A[y]||(A[x]==A[y]&&x<y);
        });
        int ans=0,Minidx=n;
        REP(i,n){
            Minidx=min(Minidx,idx[i]);
            ans=max(ans,idx[i]-Minidx);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{9,8,1,0,1,9,4,0,4,1};
    auto ans=sol.maxWidthRamp(A);
    DBG(ans);

    system("pause");
    return 0;
}
