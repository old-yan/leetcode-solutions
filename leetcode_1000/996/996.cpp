#include "utils.h"

class Solution {
    int dp[12][1<<12]={0};
    bool can[12][12]={0};
public:
    int numSquarefulPerms(vector<int>& A) {
        int n=A.size(),ratio=1;
        sort(ALL(A));
        auto next=next_different(A);
        for(int i=0;i<A.size();i=next[i]){
            ratio*=factorial(next[i]-i);
        }
        REP(i,n){
            REP(j,i){
                int sum=A[i]+A[j];
                int r=sqrt(sum);
                if(sum==r*r)can[i][j]=can[j][i]=true;
            }
        }
        for(int j=0;j<(1<<n);j++){
            for(int i=0;i<n;i++){
                if(j>>i&1){
                    int rest=j-(1<<i);
                    if(!rest)dp[i][j]=1;
                    else{
                        for(int k=0;k<n;k++){
                            if((rest>>k&1)&&can[i][k]){
                                dp[i][j]+=dp[k][rest];
                            }
                        }
                    }
                }
            }
        }
        int ans=0;
        REP(i,n)ans+=dp[i][(1<<n)-1];
        return ans/ratio;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi A{2,2,2};
    auto ans=sol.numSquarefulPerms(A);
    DBG(ans);

    system("pause");
    return 0;
}
