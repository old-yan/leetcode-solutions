#include "utils.h"

class Solution {
public:
    bool checkIfPangram(string sentence) {
        return set<char>(ALL(sentence)).size()==26;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string sentence="thequickbrownfoxjumpsoverthelazydog";
    auto ans=sol.checkIfPangram(sentence);
    DBG(ans);

    system("pause");
    return 0;
}
