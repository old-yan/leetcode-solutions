#include "utils.h"

class Solution {
    int fun(string&s){
        int val=0;
        for(char c:s){
            val=val*10+(c-'a');
        }
        return val;
    }
public:
    //简单模拟即可
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return fun(firstWord)+fun(secondWord)==fun(targetWord);
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
