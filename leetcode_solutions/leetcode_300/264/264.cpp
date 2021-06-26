#include "utils.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        vi ans{1};
        int two=0,three=0,five=0;
        while(ans.size()<n){
            int a,b,c,Min;
            a=ans[two]*2;
            b=ans[three]*3;
            c=ans[five]*5;
            Min=min(a,min(b,c));
            ans.pb(Min);
            if(a==Min)two++;
            if(b==Min)three++;
            if(c==Min)five++;
        }
        return ans.back();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=500;
    auto ans=sol.nthUglyNumber(n);
    DBG(ans);

    system("pause");
    return 0;
}
