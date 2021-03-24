#include "utils.h"

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for(int i=0,j=A.size()-1;i<j;){
            while(i<j&&A[i]%2==0)i++;
            swap(A[i],A[j]);
            while(i<j&&A[j]%2)j--;
            swap(A[i],A[j]);
        }
        return A;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,2,3,4};
    auto ans=sol.sortArrayByParity(A);
    DBGV(ans);

    system("pause");
    return 0;
}
