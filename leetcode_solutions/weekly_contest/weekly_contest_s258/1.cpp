#include "utils.h"

class Solution {
public:
    //简单模拟，找到 ch 所在下标，然后反转
    string reversePrefix(string word, char ch) {
        int pos=word.find(ch);
        if(pos!=word.npos){
            reverse(word.begin(),word.begin()+pos+1);
        }
        return word;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word="abcdefd";
    char ch='d';
    auto ans=sol.reversePrefix(word,ch);
    DBG(ans);

    system("pause");
    return 0;
}
