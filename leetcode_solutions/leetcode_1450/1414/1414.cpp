#include "utils.h"

class Solution {
    vi ma{1,1,2};
    int solve(int rest){
        if(!rest)return 0;
        int d=*lower_bound(ALL(ma),rest,greater<int>());
        return solve(rest-d)+1;
    }
public:
    int findMinFibonacciNumbers(int k) {
        while(ma.back()<k)ma.pb(ma[ma.size()-2]+ma[ma.size()-1]);
        sort(ALLR(ma));
        return solve(k);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int k=9083494;
    auto ans=sol.findMinFibonacciNumbers(k);
    DBG(ans);

    system("pause");
    return 0;
}
