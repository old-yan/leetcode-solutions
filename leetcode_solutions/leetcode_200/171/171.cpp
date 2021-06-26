#include "utils.h"

class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        ll unit=1;
        REPR(i,s.size()-1){
            ans+=(s[i]-'A'+1)*unit;
            unit*=26;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="AZY";
    auto ans=sol.titleToNumber(s);
    DBG(ans);

    system("pause");
    return 0;
}
