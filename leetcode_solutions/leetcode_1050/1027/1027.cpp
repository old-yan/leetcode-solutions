#include "utils.h"

class Solution {
    int getid[10001],cnt=0;
    int target[500][500]={0};
public:
    int longestArithSeqLength(vector<int>& A) {
        int n=A.size(),Min=10000,Max=0;
        memset(getid,0xff,sizeof(getid));
        for(int i=0;i<n;i++){
            if(getid[A[i]]<0){
                getid[A[i]]=cnt++;
                chmax(Max,A[i]);
                chmin(Min,A[i]);
            }
        }
        for(int i=0;i<n;i++){
            int ii=getid[A[i]];
            for(int j=i-1;j>=0;j--){
                int jj=getid[A[j]];
                int prev=A[j]*2-A[i];
                if(prev>=Min&&prev<=Max&&getid[prev]>=0){
                    chmax(target[ii][jj],target[jj][getid[prev]]+1);
                }
                chmax(target[ii][jj],2);
                if(A[j]==A[i])break;
            }
        }
        return *max_element(target[0],target[cnt]);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{3,6,9,12};
    auto ans=sol.longestArithSeqLength(A);
    DBG(ans);

    system("pause");
    return 0;
}
