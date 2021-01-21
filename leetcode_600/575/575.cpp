#include "utils.h"

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(ALL(candyType));
        auto end=unique(ALL(candyType));
        return min(int(end-candyType.begin()),int(candyType.size()/2));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi candyType{
        1,1,2,2,3,3
    };
    auto ans=sol.distributeCandies(candyType);
    DBG(ans);

    system("pause");
    return 0;
}
