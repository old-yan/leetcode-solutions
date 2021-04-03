#include "utils.h"

class Solution {
    vi ans;
public:
    vector<int> diStringMatch(string S) {
        int Min=0,Max=S.size();
        for(char c:S){
            if(c=='I')ans.pb(Min++);
            else ans.pb(Max--);
        }
        ans.pb(Min);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="DDI";
    auto ans=sol.diStringMatch(S);
    DBGV(ans);

    system("pause");
    return 0;
}
