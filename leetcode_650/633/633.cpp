#include "utils.h"

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(ll i=0,j=sqrt(c);i<=j;){
            if(i*i+j*j>c){
                j--;
            }
            else if(i*i+j*j<c){
                i++;
            }
            else return true;
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int c=5;
    auto ans=sol.judgeSquareSum(c);
    DBG(ans);

    system("pause");
    return 0;
}
