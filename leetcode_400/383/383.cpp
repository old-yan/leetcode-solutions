#include "utils.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int num[128]={0};
        for(char c:magazine)num[c]++;
        for(char c:ransomNote){
            if(!num[c]--)return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string ransomNote="aa";
    string magazine="aab";
    auto ans=sol.canConstruct(ransomNote,magazine);
    DBG(ans);

    system("pause");
    return 0;
}
