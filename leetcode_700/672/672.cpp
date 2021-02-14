#include "utils.h"

class Solution {
public:
    int flipLights(int n, int m) {
        if(!n||!m)return 1;
        if(n==1)return 2;
        if(n==2){
            if(m==1)return 3;
            else return 4;
        }
        if(m==1)return 4;
        else if(m==2)return 7;
        else return 8;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=3;
    int m=1;
    auto ans=sol.flipLights(n,m);
    DBG(ans);

    system("pause");
    return 0;
}
