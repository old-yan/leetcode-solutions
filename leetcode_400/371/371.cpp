#include "utils.h"

class Solution {
public:
    int getSum(int a, int b) {
        bitset<32>A(a);
        bitset<32>B(b);
        int jinwei=0;
        REP(i,32){
            if(A[i]&&B[i]&&jinwei)continue;
            if(!A[i]&&!B[i]&&!jinwei)continue;
            if((A[i]&&B[i])||(A[i]&&jinwei)||(B[i]&&jinwei)){
                A[i]=0;
                jinwei=1;
            }
            else{
                A[i]=1;
                jinwei=0;
            }
        }
        return A.to_ulong();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    

    system("pause");
    return 0;
}
