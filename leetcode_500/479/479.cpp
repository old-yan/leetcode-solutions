#include "utils.h"

class Solution {
    int n;
    string s;
    bool fun(ll val){
        ll i=val/pow(10,n)+1;
        while(i<=sqrt(val)){
            if(val%i++==0)return true;
        }
        return false;
    }
    bool dfs(int l,int r){
        if(l>r){
            return fun(s2i(s));
        }
        else{
            REPR(i,9){
                s[l]=s[r]='0'+i;
                if(dfs(l+1,r-1))return true;
            }
            return false;
        }
    }
public:
    int largestPalindrome(int _n) {
        n=_n;
        s.resize(n*2);
        if(!dfs(0,n*2-1)){
            s.resize(n*2-1);
            dfs(0,n*2-1);
        }
        return s2i(s)%1337;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=8;
    auto ans=sol.largestPalindrome(n);
    DBG(ans);

    system("pause");
    return 0;
}
