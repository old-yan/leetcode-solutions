#include "utils.h"

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1=accumulate(ALL(A),0);
        int sum2=accumulate(ALL(B),0);
        int dif=(sum1-sum2)/2;
        unordered_set<int>S(ALL(A));
        for(int b:B){
            if(S.count(b+dif))return {b+dif,b};
        }
        return {};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{1,2};
    vi B{2,3};
    auto ans=sol.fairCandySwap(A,B);
    DBGV(ans);

    system("pause");
    return 0;
}
