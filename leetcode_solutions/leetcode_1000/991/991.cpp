#include "utils.h"

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X>Y)return X-Y;
        int ans=0;
        while(Y>X){
            if(Y%2){
                Y++;
            }
            else{
                Y>>=1;
            }
            ans++;
        }
        return ans+X-Y;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int X=2;
    int Y=3;
    auto ans=sol.brokenCalc(X,Y);
    DBG(ans);

    system("pause");
    return 0;
}
