#include "utils.h"

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(ALL(nums));
        int low=0,high=nums.size();
        while(low<high){
            int mid=(low+high+1)/2;
            int bigger=nums.end()-lower_bound(ALL(nums),mid);
            if(bigger>=mid)low=mid;
            else high=mid+1;
        }
        return nums.end()-lower_bound(ALL(nums),low)==low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,5};
    auto ans=sol.specialArray(nums);
    DBG(ans);

    system("pause");
    return 0;
}
