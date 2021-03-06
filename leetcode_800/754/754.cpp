#include "utils.h"

class Solution {
public:
    int reachNumber(int _target) {
        int target=abs(_target);
        int a=sqrt(target*2);
        while(a*(a+1)/2<target)a++;
        while(a*(a+1)/2%2!=target%2)a++;
        return a;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int target=3;
    auto ans=sol.reachNumber(target);
    DBG(ans);

    system("pause");
    return 0;
}
