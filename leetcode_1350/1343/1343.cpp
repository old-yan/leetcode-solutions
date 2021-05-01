#include "utils.h"

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans=0;
        for(int i=0,j=0,sum=0;j<arr.size();i++){
            while(j<i+k)sum+=arr[j++];
            ans+=sum>=k*threshold;
            sum-=arr[i];
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{2,2,2,2,5,5,5,8};
    int k=3;
    int threshold=4;
    auto ans=sol.numOfSubarrays(arr,k,threshold);
    DBG(ans);

    system("pause");
    return 0;
}
