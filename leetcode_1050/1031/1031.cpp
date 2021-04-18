#include "utils.h"

class Solution {
    int leftL[1000],leftM[1000],rightL[1000],rightM[1000];
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n=A.size();
        for(auto a:{leftL,leftM,rightL,rightM}){
            memset(a,0x80,n*sizeof(int));
        }
        for(int i=L-1,sum=accumulate(A.begin(),A.begin()+L,0);i<n;i++){
            leftL[i]=i?max(leftL[i-1],sum):sum;
            if(i+1<n)sum+=A[i+1]-A[i-L+1];
        }
        for(int i=M-1,sum=accumulate(A.begin(),A.begin()+M,0);i<n;i++){
            leftM[i]=i?max(leftM[i-1],sum):sum;
            if(i+1<n)sum+=A[i+1]-A[i-M+1];
        }
        for(int i=n-L,sum=accumulate(A.begin()+n-L,A.end(),0);i>=0;i--){
            rightL[i]=i==n-1?sum:max(rightL[i+1],sum);
            if(i-1>=0)sum+=A[i-1]-A[i+L-1];
        }
        for(int i=n-M,sum=accumulate(A.begin()+n-M,A.end(),0);i>=0;i--){
            rightM[i]=i==n-1?sum:max(rightM[i+1],sum);
            if(i-1>=0)sum+=A[i-1]-A[i+M-1];
        }
        int ans=0;
        REP(i,n-1){
            chmax(ans,max(leftL[i]+rightM[i+1],leftM[i]+rightL[i+1]));
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{0,6,5,2,2,5,1,9,4};
    int L=1;
    int M=2;
    auto ans=sol.maxSumTwoNoOverlap(A,L,M);
    DBG(ans);

    system("pause");
    return 0;
}
