#include "utils.h"

class Solution {
public:
    int calculate(string s) {
        int x=1,y=0;
        for(char c:s){
            if(c=='A')x=x*2+y;
            else y=y*2+x;
        }
        return x+y;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="AB";
    auto ans=sol.calculate(s);
    DBG(ans);

    system("pause");
    return 0;
}
