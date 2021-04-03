#include "utils.h"

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int change[26];
        REP(i,order.size())change[order[i]-'a']='a'+i;
        for(string&s:words)for(char&c:s)c=change[c];
        return is_sorted(ALL(words));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{
        "hello","leetcode"
    };
    string order="hlabcdefgijkmnopqrstuvwxyz";
    auto ans=sol.isAlienSorted(words,order);
    DBG(ans);

    system("pause");
    return 0;
}
