#include "utils.h"

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        if(!k)return vi(n,0);
        if(k>0){
            vi ans(n,0);
            FOR(i,1,k+1)ans[0]+=code[i];
            FOR(i,1,n){
                ans[i]=ans[i-1]+code[(i+k)%n]-code[i];
            }
            return ans;
        }
        else{
            k=-k;
            vi ans(n,0);
            FOR(i,1,k+1)ans[0]+=code[n-i];
            FOR(i,1,n){
                ans[i]=ans[i-1]+code[i-1]-code[(i+n-k)%n];
            }
            return ans;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi code{5,7,1,4};
    int k=3;
    auto ans=sol.decrypt(code,k);
    DBGV(ans);

    system("pause");
    return 0;
}
