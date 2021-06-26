#include "utils.h"

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int add_pos=a.find_first_of('+',0);
        int x1=s2i(a.substr(0,add_pos));
        int y1=s2i(a.substr(add_pos+1,a.size()-add_pos-2));
        add_pos=b.find_first_of('+',0);
        int x2=s2i(b.substr(0,add_pos));
        int y2=s2i(b.substr(add_pos+1,b.size()-add_pos-2));
        return i2s(x1*x2-y1*y2)+'+'+i2s(x1*y2+x2*y1)+'i';
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string a="1+1i";
    string b="1+1i";
    auto ans=sol.complexNumberMultiply(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
