#include "utils.h"

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vi ans;
        int d=0;
        for(char c:seq){
            if(d%2){
                if(c=='(')ans.pb(0);
                else ans.pb(1);
            }
            else{
                if(c=='(')ans.pb(1);
                else ans.pb(0);
            }
            d+=c=='('?1:-1;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string seq="(()())";
    auto ans=sol.maxDepthAfterSplit(seq);
    DBGV(ans);

    system("pause");
    return 0;
}
