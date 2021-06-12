#include "utils.h"

class Solution {
public:
    char firstUniqChar(string s) {
        int cnt[26]={0};
        for(char c:s)cnt[c-'a']++;
        for(char c:s)if(cnt[c-'a']==1)return c;
        return ' ';
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abaccdeff";
    auto ans=sol.firstUniqChar(s);
    DBG(ans);

    system("pause");
    return 0;
}
