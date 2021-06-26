#include "utils.h"

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vi digits;
        vi ans;
        FOR(i,left,right+1){
            digits.clear();
            for(int j=i;j;j/=10)digits.pb(j%10);
            bool makeit=true;
            for(int a:digits){
                if(i%a){
                    makeit=false;
                    break;
                }
            }
            if(makeit)ans.pb(i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int left=1;
    int right=22;
    auto ans=sol.selfDividingNumbers(left,right);
    DBGV(ans);

    system("pause");
    return 0;
}
