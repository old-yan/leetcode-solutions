#include "utils.h"

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vi ans;
        int top=n,bottom=1;
        while(true){
            ans.pb(bottom++);
            if(!--k){
                while(bottom<=top)ans.pb(bottom++);
                break;
            }
            ans.pb(top--);
            if(!--k){
                while(top>=bottom)ans.pb(top--);
                break;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    int k=2;
    auto ans=sol.constructArray(n,k);
    DBGV(ans);

    system("pause");
    return 0;
}
