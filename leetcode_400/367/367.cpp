#include "utils.h"

class Solution {
public:
    bool isPerfectSquare(int num) {
        ll low=1,high=num;
        while(low<high){
            ll mid=(low+high)/2;
            if(mid*mid>=num)high=mid;
            else low=mid+1;
        }
        return low*low==num;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=16;
    auto ans=sol.isPerfectSquare(num);
    DBG(ans);

    system("pause");
    return 0;
}
