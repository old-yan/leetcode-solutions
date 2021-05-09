#include "utils.h"

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size(),ans=0;
        for(int i=0;i<n;i++){
            ans+=arr[i]*((i>>1)+1)*(((n-i-1)>>1)+1);
            ans+=arr[i]*((i+1)>>1)*((n-i)>>1);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{1,4,2,5,3};
    auto ans=sol.sumOddLengthSubarrays(arr);
    DBG(ans);

    system("pause");
    return 0;
}
