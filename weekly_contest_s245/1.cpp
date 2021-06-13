#include "utils.h"

class Solution {
public:
    //检查每种字符的数量，只要是words的长度的倍数就ok
    bool makeEqual(vector<string>& words) {
        int cnt[26]={0};
        for(string&s:words){
            for(char c:s)cnt[c-'a']++;
        }
        REP(i,26){
            if(cnt[i]%words.size())return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{
        "abc","aabc","bc"
    };
    auto ans=sol.makeEqual(words);
    DBG(ans);

    system("pause");
    return 0;
}
