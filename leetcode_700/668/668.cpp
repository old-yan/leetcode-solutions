#include "utils.h"

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low=1,high=m*n;
        while(low<high){
            int mid=(low+high)/2;
            int cnt=0;
            FOR(i,1,m+1){
                cnt+=min(int(mid/i),n);
            }
            if(cnt>=k)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int m=3;
    int n=3;
    int k=5;
    auto ans=sol.findKthNumber(m,n,k);
    DBG(ans);

    system("pause");
    return 0;
}
