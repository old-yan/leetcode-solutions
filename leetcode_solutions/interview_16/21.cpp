#include "utils.h"

class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        ll sum1=accumulate(ALL(array1),0ll);
        ll sum2=accumulate(ALL(array2),0ll);
        if((sum1+sum2)%2)return {};
        int d=(sum2-sum1)/2;
        unordered_set<int>S(ALL(array1));
        for(int a:array2){
            if(S.count(a-d)){
                return {a-d,a};
            }
        }
        return {};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi array1{4, 1, 2, 1, 1, 2};
    vi array2{3, 6, 3, 3};
    auto ans=sol.findSwapValues(array1,array2);
    DBGV(ans);

    system("pause");
    return 0;
}
