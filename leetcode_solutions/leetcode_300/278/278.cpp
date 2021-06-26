#include "utils.h"

bool (*isBadVersion)(int);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1,high=n;
        while(low<high){
            int mid=(low+high)/2;
            if(isBadVersion(mid))high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=100;
    isBadVersion=[](int version){return version>=80;};
    auto ans=sol.firstBadVersion(n);
    DBG(ans);

    system("pause");
    return 0;
}
