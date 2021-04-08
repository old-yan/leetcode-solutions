#include "utils.h"

class Solution {
    int rightBigger[20000];
    int rightSmaller[20000];
    bool dp[20000][2];
    int n;
    void getRightBigger(vi&arr){
        map<int,int>M;
        REPR(i,n-1){
            auto it=M.lower_bound(arr[i]);
            if(it!=M.end())rightBigger[i]=it->second;
            else rightBigger[i]=0;
            M[arr[i]]=i;
        }
    }
    void getRightSmaller(vi&arr){
        map<int,int>M;
        REPR(i,n-1){
            auto it=M.upper_bound(arr[i]);
            if(it!=M.begin())rightSmaller[i]=prev(it)->second;
            else rightSmaller[i]=0;
            M[arr[i]]=i;
        }
    }
public:
    int oddEvenJumps(vector<int>& arr) {
        n=arr.size();
        getRightBigger(arr);
        getRightSmaller(arr);
        dp[n-1][0]=dp[n-1][1]=true;
        int ans=1;
        REPR(i,n-2){
            dp[i][0]=rightBigger[i]&&dp[rightBigger[i]][1];
            dp[i][1]=rightSmaller[i]&&dp[rightSmaller[i]][0];
            if(dp[i][0])ans++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,3,2,1,4,4,5};
    auto ans=sol.oddEvenJumps(arr);
    DBG(ans);

    system("pause");
    return 0;
}
