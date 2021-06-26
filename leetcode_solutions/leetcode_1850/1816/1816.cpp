#include "utils.h"

class Solution {
public:
    string truncateSentence(string s, int k) {
        auto v=split(s);
        string ans=v[0];
        FOR(i,1,k){
            ans+=" "+v[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="Hello how are you Contestant";
    int k=4;
    auto ans=sol.truncateSentence(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
