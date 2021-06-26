#include "utils.h"

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int cnt[7]={0},up[7]={0},down[7]={0};
        int n=A.size();
        REP(i,n){
            cnt[A[i]]++;
            if(A[i]!=B[i])cnt[B[i]]++;
            up[A[i]]++;
            down[B[i]]++;
        }
        int ans=INT_MAX;
        FOR(i,1,7){
            if(cnt[i]==n){
                chmin(ans,n-up[i]);
                chmin(ans,n-down[i]);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{2,1,2,4,2,2};
    vi B{5,2,6,2,3,2};
    auto ans=sol.minDominoRotations(A,B);
    DBG(ans);

    system("pause");
    return 0;
}
