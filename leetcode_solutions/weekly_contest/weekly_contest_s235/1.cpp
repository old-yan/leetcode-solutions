#include "utils.h"

class Solution {
public:
    //找到第k个空格，返回之前的子字符串
    string truncateSentence(string s, int k) {
        int i=0;
        while(k--){
            i=s.find_first_of(' ',i+1);
        }
        return s.substr(0,i);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="Hello how are you Contestant";
    int k=4;
    auto ans=sol.truncateSentence(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
