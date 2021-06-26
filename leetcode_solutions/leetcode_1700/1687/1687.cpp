#include "utils.h"

class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n=boxes.size();
        int next[n];
        for(int i=0,j;i<n;){
            for(j=i+1;j<n&&boxes[j][0]==boxes[i][0];j++);
            while(i<j)next[i++]=j;
        }
        int _dp[n+1];
        auto dp=_dp+1;
        dp[-1]=0;
        for(int i=0,j=0,sum=0,k=0;i<n;i++){
            sum+=boxes[i][1];
            k+=!i||(boxes[i][0]!=boxes[i-1][0]);
            while(sum>maxWeight||i-j+1>maxBoxes){
                k-=boxes[j][0]!=boxes[j+1][0];
                sum-=boxes[j++][1];
            }
            dp[i]=dp[j-1]+k+1;
            if(j&&boxes[j][0]==boxes[j-1][0]&&i>=next[j]){
                chmin(dp[i],dp[next[j]-1]+k);
            }
        }
        return dp[n-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vvi boxes=makevvi("[[1,1],[2,1],[1,1]]");
    int portsCount=2;
    int maxBoxes=3;
    int maxWeight=3;
    auto ans=sol.boxDelivering(boxes,portsCount,maxBoxes,maxWeight);
    DBG(ans);

    system("pause");
    return 0;
}
