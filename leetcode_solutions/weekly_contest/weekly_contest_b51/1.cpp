#include "utils.h"

class Solution {
    char shift(char c,char d){
        return c+(d-'0');
    }
public:
    //简单模拟
    string replaceDigits(string s) {
        for(int i=1;i<s.size();i+=2){
            s[i]=shift(s[i-1],s[i]);
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
