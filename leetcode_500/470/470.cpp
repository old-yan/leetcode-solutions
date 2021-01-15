#include "utils.h"

int (*rand7)();

class Solution {
public:
    int rand10() {
        int val;
        do{
            val=(rand7()-1)*7+rand7();
        }while(val>40);
        return (val-1)%10+1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    rand7=[]{
        return rand()%7+1;
    };
    DBG(sol.rand10());
    DBG(sol.rand10());
    DBG(sol.rand10());
    DBG(sol.rand10());
    DBG(sol.rand10());
    DBG(sol.rand10());
    DBG(sol.rand10());
    DBG(sol.rand10());
    DBG(sol.rand10());
    DBG(sol.rand10());

    system("pause");
    return 0;
}
