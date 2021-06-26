#include "utils.h"

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans(n);
        FOR(i,1,n+1){
            if(i%3==0&&i%5==0)ans[i-1]="FizzBuzz";
            else if(i%3==0)ans[i-1]="Fizz";
            else if(i%5==0)ans[i-1]="Buzz";
            else ans[i-1]=i2s(i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=15;
    auto ans=sol.fizzBuzz(n);
    DBGV(ans);

    system("pause");
    return 0;
}
