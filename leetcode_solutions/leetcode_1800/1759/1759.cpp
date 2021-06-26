#include "utils.h"

class Solution {
public:
    int countHomogenous(string s) {
        ll ans=0;
        for(int i=0,j=0;i<s.size();i=j){
            for(j=i+1;j<s.size()&&s[j]==s[i];j++);
            ans+=(ll)(j-i+1)*(j-i)/2;
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abbcccaa";
    auto ans=sol.countHomogenous(s);
    DBG(ans);

    system("pause");
    return 0;
}
