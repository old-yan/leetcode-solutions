#include "utils.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans=0;
        for(int i=0,j;i+2<A.size();i=j){
            int d=A[i+1]-A[i];
            for(j=i+1;j+1<A.size()&&A[j+1]-A[j]==d;j++);
            ans+=(j-i)*(j-i-1)/2;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,2,3,4,6,8,9};
    auto ans=sol.numberOfArithmeticSlices(A);
    DBG(ans);

    system("pause");
    return 0;
}