#include "EulerPrime.h"
#include "Union.h"
#include "utils.h"

int first[100001];
Union u(100000);
class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        static EulerPrime<100000>ep;
        memset(first,0xff,sizeof(first));
        u.reset();
        REP(i,A.size()){
            ep.getPrimeFactors<0>(A[i]);
            REP(_,ep.plen){
                int a=ep.pf[_];
                if(first[a]>=0){
                    u.unite(i,first[a]);
                }
                else first[a]=i;
            }
        }
        int ans=0;
        REP(i,A.size()){
            if(u.Find(i)==i)chmax(ans,u.size[i]);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{4,6,15,35};
    auto ans=sol.largestComponentSize(A);
    DBG(ans);

    system("pause");
    return 0;
}
