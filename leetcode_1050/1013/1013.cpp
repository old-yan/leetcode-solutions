#include "utils.h"

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=accumulate(ALL(arr),0);
        if(sum%3)return false;
        int part=sum/3,cnt=0,idx=0;
        while(idx<arr.size()){
            cnt+=arr[idx++];
            if(cnt==part)break;
        }
        if(idx==arr.size())return false;
        cnt=0;
        while(idx<arr.size()){
            cnt+=arr[idx++];
            if(cnt==part)break;
        }
        return idx<arr.size();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi arr{3,3,6,5,-2,2,5,1,-9,4};
    auto ans=sol.canThreePartsEqualSum(arr);
    DBG(ans);

    system("pause");
    return 0;
}
