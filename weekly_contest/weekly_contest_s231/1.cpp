#include "utils.h"

class Solution {
public:
    bool checkOnesSegment(string s) {
        //先找出第一个零
        int first_zero=s.find_first_of('0');
        //没零说明全是一
        if(first_zero<0)return true;
        //有零的话看看后面还有没有一
        int second_one=s.find_first_of('1',first_zero);
        return second_one<0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="110001";
    auto ans=sol.checkOnesSegment(s);
    DBG(ans);

    system("pause");
    return 0;
}
