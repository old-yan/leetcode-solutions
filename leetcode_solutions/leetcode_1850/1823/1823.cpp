#include "utils.h"

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>Q;
        FOR(i,1,n+1)Q.push(i);
        while(Q.size()>1){
            REP(i,k-1){
                auto p=Q.front();
                Q.pop();
                Q.push(p);
            }
            Q.pop();
        }
        return Q.front();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=5;
    int k=2;
    auto ans=sol.findTheWinner(n,k);
    DBG(ans);

    system("pause");
    return 0;
}
