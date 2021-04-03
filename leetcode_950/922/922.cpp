#include "utils.h"

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for(int i=0,j=1;i<A.size()&&j<A.size();){
            while(i<A.size()&&A[i]%2==0)i+=2;
            if(i>=A.size())break;
            swap(A[i],A[j]);
            j+=2;
            while(j<A.size()&&A[j]%2)j+=2;
            if(j>=A.size())break;
            swap(A[i],A[j]);
            i+=2;
        }
        return A;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{4,2,5,7};
    auto ans=sol.sortArrayByParityII(A);
    DBGV(ans);

    system("pause");
    return 0;
}
