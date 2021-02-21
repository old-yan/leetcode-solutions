#include "utils.h"

class Solution {
public:
    string toLowerCase(string str) {
        for(char&c:str)c=tolower(c);
        return str;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string str="Hello";
    auto ans=sol.toLowerCase(str);
    DBG(ans);

    system("pause");
    return 0;
}
