#include "utils.h"

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        auto rnk=getrank2(arr);
        for(int&a:rnk)a++;
        return rnk;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{40,10,20,30};
    auto ans=sol.arrayRankTransform(arr);
    DBGV(ans);

    system("pause");
    return 0;
}
