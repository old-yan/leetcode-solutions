#include "utils.h"

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int goup,n=arr.size();
        for(goup=n-1;goup-1>=0&&arr[goup-1]<=arr[goup];goup--);
        if(!goup)return 0;
        int ans=goup;
        for(int i=0;i<n;i++){
            if(i&&arr[i]<arr[i-1])break;
            while(goup<n&&arr[goup]<arr[i])goup++;
            chmin(ans,goup-i-1);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,2,3,10,4,2,3,5};
    auto ans=sol.findLengthOfShortestSubarray(arr);
    DBG(ans);

    system("pause");
    return 0;
}
