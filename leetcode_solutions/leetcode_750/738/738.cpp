#include "utils.h"

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s=i2s(N);
        string ans=s;
        REP(i,ans.size()){
            for(ans[i]='9';;ans[i]--){
                FOR(j,i+1,ans.size())ans[j]=ans[i];
                if(ans<=s)break;
            }
        }
        return s2i(ans);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=10;
    auto ans=sol.monotoneIncreasingDigits(N);
    DBG(ans);

    system("pause");
    return 0;
}
