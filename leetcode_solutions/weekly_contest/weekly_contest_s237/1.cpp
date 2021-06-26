#include "utils.h"

class Solution {
public:
    //set去重统计
    bool checkIfPangram(string s) {
        set<char>S;
        for(char c:s)S.insert(c);
        return S.size()==26;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abcdefghijklmnopqrstuvwxya";
    auto ans=sol.checkIfPangram(s);
    DBG(ans);

    system("pause");
    return 0;
}
