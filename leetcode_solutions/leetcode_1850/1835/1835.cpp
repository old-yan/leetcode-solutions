#include "utils.h"

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        return accumulate(ALL(arr1),0,[](int x,int y){return x^y;})&accumulate(ALL(arr2),0,[](int x,int y){return x^y;});
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr1{1,2,3};
    vi arr2{6,5};
    auto ans=sol.getXORSum(arr1,arr2);
    DBG(ans);

    system("pause");
    return 0;
}
