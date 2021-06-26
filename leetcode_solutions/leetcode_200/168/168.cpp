#include "utils.h"

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n){
            int i=n%26;
            if(!i){
                ans+='Z';
            }
            else ans+='A'+i-1;
            --n/=26;
        }
        reverse(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=701;
    auto ans=sol.convertToTitle(n);
    DBG(ans);

    system("pause");
    return 0;
}