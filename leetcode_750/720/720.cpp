#include "utils.h"

class Solution {
public:
    string longestWord(vector<string>& words) {

    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{
        "w","wo","wor","worl", "world"
    };
    auto ans=sol.longestWord(words);
    DBG(ans);

    system("pause");
    return 0;
}
