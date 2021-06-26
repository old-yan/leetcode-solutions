#include "utils.h"

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        ll ans=0;
        int odd=0,even=1,sum=0;
        for(int a:arr){
            sum=(sum+a)%2;
            if(sum%2){
                ans+=even;
                odd++;
            }
            else{
                ans+=odd;
                even++;
            }
        }
        return ans%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{2,4,6};
    auto ans=sol.numOfSubarrays(arr);
    DBG(ans);

    system("pause");
    return 0;
}
