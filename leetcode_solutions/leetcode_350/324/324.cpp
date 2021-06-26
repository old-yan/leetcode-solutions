#include "utils.h"

class Solution {
public:
    void wiggleSort(vector<int>&nums) {
        int k=(nums.size()+1)/2;
        nth_element(&nums[0],&nums[0]+k-1,&nums[0]+nums.size());
        int median=nums[k-1];
        int start=nums.size()%2?nums.size()-1:nums.size()-2;
        #define a(i) (i<(nums.size()+1)/2?nums[start-i*2]:nums[nums.size()*2-1-i*2])
        int i1=0,i2=nums.size()-1,i=0;
        while(i<=i2){
            if(a(i)<median){
                swap(a(i),a(i1));
                i++,i1++;
            }
            else if(a(i)>median){
                swap(a(i),a(i2));
                i2--;
            }
            else i++;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,3,2,2,3,1};
    sol.wiggleSort(nums);
    DBGV(nums);

    system("pause");
    return 0;
}
