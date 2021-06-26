#include "utils.h"

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        REP(i,max(word1.size(),word2.size())){
            if(i<word1.size())ans+=word1[i];
            if(i<word2.size())ans+=word2[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word1="abc";
    string word2="pqr";
    auto ans=sol.mergeAlternately(word1,word2);
    DBG(ans);

    system("pause");
    return 0;
}
