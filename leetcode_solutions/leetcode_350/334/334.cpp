#include "utils.h"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        ll smallest_one=(ll)INT_MAX+1,smallest_two=(ll)INT_MAX+1,smallest_three=(ll)INT_MAX+1;
        for(int a:nums){
            if(a>smallest_two){
                chmin(smallest_three,(ll)a);
            }
            if(a>smallest_one){
                chmin(smallest_two,(ll)a);
            }
            chmin(smallest_one,(ll)a);
        }
        return smallest_three<=INT_MAX;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4,5};
    auto ans=sol.increasingTriplet(nums);
    DBG(ans);

    system("pause");
    return 0;
}
