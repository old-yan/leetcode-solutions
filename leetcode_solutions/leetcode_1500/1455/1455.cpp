#include "utils.h"

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto v=split(sentence);
        REP(i,v.size()){
            if(v[i].size()>=searchWord.size()&&v[i].substr(0,searchWord.size())==searchWord){
                return i+1;
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string sentence="i love eating burger";
    string searchWord="burg";
    auto ans=sol.isPrefixOfWord(sentence,searchWord);
    DBG(ans);

    system("pause");
    return 0;
}
