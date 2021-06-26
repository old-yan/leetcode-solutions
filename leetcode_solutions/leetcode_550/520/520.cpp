#include "utils.h"

class Solution {
public:
    bool detectCapitalUse(string word) {
        int Capital_count=0;
        for(char c:word){
            if(isupper(c))Capital_count++;
        }
        if(!Capital_count||Capital_count==word.size())return true;
        if(Capital_count==1)return isupper(word[0]);
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word="FlaG";
    auto ans=sol.detectCapitalUse(word);
    DBG(ans);

    system("pause");
    return 0;
}
