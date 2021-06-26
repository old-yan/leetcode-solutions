#include "utils.h"

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int ans=K;
        int n=A.size();
        for(int i=0,j=0,k=0;i<n;i++){
            while(j<n&&(k<K||(k==K&&A[j]))){
                if(!A[j++])k++;
            }
            chmax(ans,j-i);
            if(!A[i])k--;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int K=3;
    auto ans=sol.longestOnes(A,K);
    DBG(ans);

    system("pause");
    return 0;
}
