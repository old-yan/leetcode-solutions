#include "utils.h"

class Solution {
public:
    string defangIPaddr(string address) {
        auto v=split(address,'.');
        auto s="[.]";
        return v[0]+s+v[1]+s+v[2]+s+v[3];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string address="1.1.1.1";
    auto ans=sol.defangIPaddr(address);
    DBG(ans);

    system("pause");
    return 0;
}
