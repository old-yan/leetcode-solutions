#include "utils.h"

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vi ans;
        ans.pb(first);
        for(int a:encoded){
            ans.pb(ans.back()^a);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi encoded{1,2,3};
    int first=1;
    auto ans=sol.decode(encoded,first);
    DBGV(ans);

    system("pause");
    return 0;
}
