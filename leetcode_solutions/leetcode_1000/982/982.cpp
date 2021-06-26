#include "FWT.h"
#include "utils.h"

class Solution {
    int B[1<<16]={0};
public:
	int countTriplets(vector<int>& A) {
        int n=A.size(),Max=0,m;
        for(int a:A){
            B[a]++;
            Max=max(Max,a);
        }
        for(m=32;m<=Max;m<<=1);
        FWT_and<1,int>(B,m);
        for(int&b:B)b*=b*b;
        FWT_and<0,int>(B,m);
        return B[0];
	}
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{2,1,3};
    auto ans=sol.countTriplets(A);
    DBG(ans);

    system("pause");
    return 0;
}
