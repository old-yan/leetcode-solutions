#include "utils.h"

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)return 0;
        bool banned[n];
        memset(banned,0,sizeof(banned));
        int ans=0;
        FOR(i,2,n){
            if(!banned[i]){
                ans++;
                for(int j=i;j<n;j+=i)banned[j]=true;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    auto ans=sol.countPrimes(n);
    DBG(ans);

    system("pause");
    return 0;
}
