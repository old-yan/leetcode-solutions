#include "utils.h"

class Solution {
public:
    int magicalString(int n) {
        char c[2001]="122";
        int idx=0;
        bool signal=true;
        for(int i=0,j;idx<n;i++){
            if(signal)REP(k,c[i]-'0')c[idx++]='1';
            else REP(k,c[i]-'0')c[idx++]='2';
            signal=!signal;
        }
        int ans=0;
        REP(i,n)if(c[i]=='1')ans++;
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=100;
    auto ans=sol.magicalString(n);
    DBG(ans);

    system("pause");
    return 0;
}
