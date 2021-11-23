#include "utils.h"

class Solution {
public:
    //用一个字典，word1 里的字符贡献为 1，word2 里的字符贡献为 -1。
    //最后看抵消之后，能否停留在 [-3,3] 范围内
    bool checkAlmostEquivalent(string word1, string word2) {
        int cnt[128]={0};
        for(char c:word1)cnt[c]++;
        for(char c:word2)cnt[c]--;
        for(int a:cnt){
            if(a<-3 or a>3)return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word1="abcdeef";
    string word2="abaaacc";
    auto ans=sol.checkAlmostEquivalent(word1,word2);
    DBG(ans);

    system("pause");
    return 0;
}