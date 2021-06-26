#include "utils.h"

class Solution {
public:
    int numSub(string s) {
        ll ans=0;
        int cnt=0;
        for(char c:s){
            if(c=='0'){
                ans+=(ll)cnt*(cnt+1)/2;
                cnt=0;
            }
            else cnt++;
        }
        ans+=(ll)cnt*(cnt+1)/2;
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="0110111";
    auto ans=sol.numSub(s);
    DBG(ans);

    system("pause");
    return 0;
}
