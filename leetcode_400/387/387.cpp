#include "utils.h"

class Solution {
public:
    int firstUniqChar(string s) {
        int num[128]={0};
        for(char c:s)num[c]++;
        REP(i,s.size()){
            if(num[s[i]]==1)return i;
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="loveleetcode";
    auto ans=sol.firstUniqChar(s);
    DBG(ans);

    system("pause");
    return 0;
}
