#include "utils.h"

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        auto copy=nums;
        sort(ALL(copy));
        for(int i=0;i<nums.size();i+=2){
            nums[i]=copy[i/2];
        }
        for(int i=1;i<nums.size();i+=2){
            nums[i]=copy[(nums.size()+i)/2];
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{5,3,1,2,3};
    sol.wiggleSort(nums);

    system("pause");
    return 0;
}
