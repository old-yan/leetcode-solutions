#include "utils.h"

int (*guess)(int);

class Solution {
public:
    int guessNumber(int n) {
        ll low=1,high=n;
        while(low<high){
            ll mid=(low+high)/2;
            if(guess(mid)<=0)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=10;
    guess=[](int num){
        if(num>6)return -1;
        else if(num<6)return 1;
        else return 0;
    };
    auto ans=sol.guessNumber(n);
    DBG(ans);

    system("pause");
    return 0;
}
