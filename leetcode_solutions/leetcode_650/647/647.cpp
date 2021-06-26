#include "utils.h"

class Solution {
public:
    int countSubstrings(string s) {
        vi arm=getarm(s);
        int ans=0;
        FOR(i,2,s.size()*2+1){
            ans+=(arm[i]+1)/2;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abc";
    auto ans=sol.countSubstrings(s);
    DBG(ans);

    system("pause");
    return 0;
}
