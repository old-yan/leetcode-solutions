#include "utils.h"

int bigger[4002];
int _dp[2002]={4001},*dp=_dp+1;
class Solution {
    int l;
    void init(vector<int>&arr1,vector<int>&arr2){
        static int data[4000];
        memcpy(data+arr2.size(),arr1.data(),arr1.size()*4);
        sort(data+arr2.size(),data+arr1.size()+arr2.size());
        sort(ALL(arr2));
        merge(data+arr2.size(),data+arr1.size()+arr2.size(),ALL(arr2),data);
        l=unique(data,data+arr1.size()+arr2.size())-data;
        for(int&a:arr1)a=upper_bound(data,data+l,a)-data;
        for(int&a:arr2)a=upper_bound(data,data+l,a)-data;
        int cur=0;
        for(int a:arr2){
            while(cur<a)bigger[cur++]=a;
        }
        while(cur<=4001)bigger[cur++]=4001;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        init(arr1,arr2);
        int n=arr1.size(),left=0,right=1;
        dp[0]=dp[1]=0;
        REP(i,n){
            FORR(j,right,left){
                if(arr1[i]>dp[j]){
                    dp[j]=min(arr1[i],bigger[dp[j-1]]);
                }
                else{
                    dp[j]=bigger[dp[j-1]];
                    if(dp[j]>=4001){
                        left=j+1;
                        break;
                    }
                }
            }
            if(left>right)return -1;
            if(dp[right]<dp[right-1]){
                ++right;
                dp[right]=dp[right-1];
            }
        }
        return left;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr1{1,4,2,5};
    vi arr2{1,2,3};
    auto ans=sol.makeArrayIncreasing(arr1,arr2);
    DBG(ans);

    system("pause");
    return 0;
}
