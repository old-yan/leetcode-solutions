#include "utils.h"

class Solution {
public:
    int maximum69Number (int num) {
        string s=i2s(num);
        for(char&c:s){
            if(c=='6'){
                c='9';
                break;
            }
        }
        return s2i(s);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=9669;
    auto ans=sol.maximum69Number(num);
    DBG(ans);

    system("pause");
    return 0;
}
