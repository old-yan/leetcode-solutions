#include "utils.h"

class Solution {
public:
    char findTheDifference(string s, string t) {
        multiset<char>S;
        for(char c:t)S.insert(c);
        for(char c:s)S.erase(S.find(c));
        return *S.begin();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abcd";
    string t="abcde";
    auto ans=sol.findTheDifference(s,t);
    DBG(ans);

    system("pause");
    return 0;
}
