#include "utils.h"

class Solution {
public:
    int numWays(string s) {
        int one=0,n=s.size();
        for(char c:s)one+=c=='1';
        if(!one)return combination(n-1,2);
        int a=0,b=0;
        for(int i=0,j=0;i<n;i++){
            j+=s[i]=='1';
            if(j*3==one)a++;
            if(j*3==one*2)b++;
        }
        return (ll)a*b%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="10101";
    auto ans=sol.numWays(s);
    DBG(ans);

    system("pause");
    return 0;
}
