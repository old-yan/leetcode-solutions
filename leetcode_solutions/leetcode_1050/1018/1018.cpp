#include "utils.h"

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool>ans;
        int cur=0;
        for(int a:A){
            cur=(cur*2+a)%5;
            ans.pb(!cur);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{0,1,1,1,1,1};
    auto ans=sol.prefixesDivBy5(A);
    DBGV(ans);

    system("pause");
    return 0;
}
