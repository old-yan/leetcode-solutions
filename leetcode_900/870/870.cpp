#include "utils.h"

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vi A_idxes(n);
        iota(ALL(A_idxes),0);
        sort(ALL(A_idxes),[&](int x,int y){return A[x]<A[y];});
        vi B_idxes(n);
        iota(ALL(B_idxes),0);
        sort(ALL(B_idxes),[&](int x,int y){return B[x]<B[y];});
        vi wasted;
        vi ans(n);
        for(int i=0,j=0;j<n;j++){
            while(i<n&&A[A_idxes[i]]<=B[B_idxes[j]]){
                wasted.pb(A[A_idxes[i++]]);
            }
            if(i<n)ans[B_idxes[j]]=A[A_idxes[i++]];
            else{
                while(j<n){
                    ans[B_idxes[j++]]=wasted.back();
                    wasted.pop_back();
                }
                break;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{2,7,11,15};
    vi B{1,10,4,11};
    auto ans=sol.advantageCount(A,B);
    DBGV(ans);

    system("pause");
    return 0;
}
