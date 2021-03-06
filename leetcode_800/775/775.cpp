#include "utils.h"

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for(int i=0;i<A.size();){
            if(A[i]==i)i++;
            else if(A[i]==i+1&&A[i+1]==i)i+=2;
            else return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,0,2};
    auto ans=sol.isIdealPermutation(A);
    DBG(ans);

    system("pause");
    return 0;
}
