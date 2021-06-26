#include "utils.h"

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1)return '1';
        else{
            if(k==1<<(n-1))return '1';
            else if(k>1<<(n-1))return '0'+1-(findKthBit(n-1,(1<<n)-k)-'0');
            else return findKthBit(n-1,k);
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=4;
    int k=11;
    auto ans=sol.findKthBit(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
