#include "utils.h"

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        return accumulate(ALL(stones),0,[&](int cnt,char c){return cnt+=jewels.find(c)<jewels.size();});
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string jewels="aA";
    string stones="aAAbbbb";
    auto ans=sol.numJewelsInStones(jewels,stones);
    DBG(ans);

    system("pause");
    return 0;
}
