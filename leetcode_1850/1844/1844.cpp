#include "utils.h"

class Solution {
    char shift(char c,char x){
        return c+(x-'0');
    }
public:
    string replaceDigits(string s) {
        for(int i=0;i<s.size();i+=2){
            s[i+1]=shift(s[i],s[i+1]);
        }
        return s;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="a1c1e1";
    auto ans=sol.replaceDigits(s);
    DBG(ans);

    system("pause");
    return 0;
}
