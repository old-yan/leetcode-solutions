#include "utils.h"

class Solution {
    int f(string&s){
        int val=0;
        for(char c:s)val=val*10+c-'a';
        return val;
    }
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return f(firstWord)+f(secondWord)==f(targetWord);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string firstWord="acb";
    string secondWord="cba";
    string targetWord="cdb";
    auto ans=sol.isSumEqual(firstWord,secondWord,targetWord);
    DBG(ans);

    system("pause");
    return 0;
}
