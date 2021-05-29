#include "utils.h"

class Solution {
public:
    int paintingPlan(int n, int k) {
        if(!k)return 1;
        int ans=0;
        REP(r,n+1)
            REP(c,n+1){
                if(r==n&&c<n)continue;
                if(c==n&&r<n)continue;
                if((r+c)*n-r*c==k){
                    ans+=combination(n,r)*combination(n,c);
                }
            }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=2;
    int k=2;
    auto ans=sol.paintingPlan(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
