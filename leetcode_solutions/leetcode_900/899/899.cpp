#include "SuffixArray.h"
#include "utils.h"

class Solution {
public:
    string orderlyQueue(string S, int K) {
        if(K==1){
            SuffixArray<>SA(S+S);
            auto it=min_element(SA.rk,SA.rk+S.size())-SA.rk;
            return S.substr(it)+S.substr(0,it);
        }
        else{
            sort(ALL(S));
            return S;
        }

    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="baaca";
    int K=3;
    auto ans=sol.orderlyQueue(S,K);
    DBG(ans);

    system("pause");
    return 0;
}
