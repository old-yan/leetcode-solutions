#include "utils.h"

class Solution {
public:
    double myPow(double x, ll n) {
        if(n<0){
            x=1/x,n*=-1;
        }
        double res=1;
	    while(n){
		    if(n&1)res=res*x;
		    x*=x;
		    n>>=1;
	    }
	    return res;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    double x=2.1;
    int n=3;
    auto ans=sol.myPow(x,n);
    DBG(ans);

    system("pause");
    return 0;
}
