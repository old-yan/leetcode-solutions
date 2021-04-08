#include "utils.h"

class Solution {
public:
    int clumsy(int N) {
        if(N%4==2){
            return N==2?2:N+2;
        }
        else if(N%4==3){
            return N==3?6:N-1;
        }
        else if(N%4==1){
            return N==1?1:N+2;
        }
        else{
            return N==4?7:N+1;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=10;
    auto ans=sol.clumsy(N);
    DBG(ans);

    system("pause");
    return 0;
}
