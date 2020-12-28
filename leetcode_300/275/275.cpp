#include "utils.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low=0,high=citations.size();
        while(low<high){
            int mid=(low+high)/2;
            if(citations[mid]>=citations.size()-mid)high=mid;
            else low=mid+1;
        }
        return citations.size()-low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi citations{0,1,3,5,6};
    auto ans=sol.hIndex(citations);
    DBG(ans);

    system("pause");
    return 0;
}
