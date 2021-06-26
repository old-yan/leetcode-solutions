#include "utils.h"

class Solution {
public:
    int minFlips(string target) {
        int cur=0;
        int ans=0;
        for(char c:target){
            if(c=='0'+cur%2)continue;
            cur^=1;
            ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string target="10111";
    auto ans=sol.minFlips(target);
    DBG(ans);

    system("pause");
    return 0;
}
