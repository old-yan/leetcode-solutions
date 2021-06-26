#include "utils.h"

class Solution {
public:
    vector<int> sumZero(int n) {
        vi ans(n,0);
        if(n%2){
            FOR(i,1,n)ans[i]=i%2?(i+1)/2:-(i+1)/2;
        }
        else{
            REP(i,n)ans[i]=i%2?(i+2)/2:-(i+2)/2;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    auto ans=sol.sumZero(n);
    DBG(ans);

    system("pause");
    return 0;
}
