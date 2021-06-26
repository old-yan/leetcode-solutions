#include "utils.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j;
        for(i=j=0;i<nums.size();){
            if(nums[i]){
                if(i==j){
                    i++;
                    j++;
                }
                else{
                    swap(nums[i],nums[j++]);
                }
            }
            else{
                i++;
            }
        }
    }
};


int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{0,1,0,3,12};
    sol.moveZeroes(nums);
    DBGV(nums);

    system("pause");
    return 0;
}
