#include "utils.h"

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if(a>b)swap(a,b);
        if(b>c)swap(b,c);
        if(a>b)swap(a,b);
        if(c>a+b)return a+b;
        else return (a+b+c)/2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int a=2;
    int b=4;
    int c=6;
    auto ans=sol.maximumScore(a,b,c);
    DBG(ans);

    system("pause");
    return 0;
}
