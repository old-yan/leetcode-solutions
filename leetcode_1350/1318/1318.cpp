#include "utils.h"

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        REP(i,32){
            int aa=a>>i&1;
            int bb=b>>i&1;
            int cc=c>>i&1;
            if(cc){
                ans+=!aa&&!bb;
            }
            else ans+=aa+bb;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int a=2;
    int b=6;
    int c=5;
    auto ans=sol.minFlips(a,b,c);
    DBG(ans);

    system("pause");
    return 0;
}
