#include "utils.h"

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vi endWith(n,0x3f3f3f3f),startWith(n,0x3f3f3f3f);
        for(int left=0,right=0,sum=0;right<n;right++){
            sum+=arr[right];
            while(sum>target)sum-=arr[left++];
            if(sum==target)endWith[right]=right-left+1;
        }
        for(int left=0,right=0,sum=0;right<n;left++){
            while(right<arr.size()&&sum<target)sum+=arr[right++];
            if(sum==target)startWith[left]=right-left;
            sum-=arr[left];
        }
        partial_sum(ALL(endWith),endWith.begin(),[](int x,int y){return min(x,y);});
        partial_sum(ALLR(startWith),startWith.rbegin(),[](int x,int y){return min(x,y);});
        int ans=INT_MAX;
        FOR(i,1,n){
            chmin(ans,endWith[i-1]+startWith[i]);
        }
        return ans>=0x3f3f3f3f?-1:ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{7,3,4,7};
    int target=7;
    auto ans=sol.minSumOfLengths(arr,target);
    DBG(ans);

    system("pause");
    return 0;
}
