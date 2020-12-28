#include "utils.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        if(!k)return;
        int count=0;
        for(int i=0,j;i<n;i++){
            if(count==n)break;
            int temp=nums[i];
            for(j=(i+n-k)%n;j!=i;j=(j+n-k)%n){
                nums[(j+k)%n]=nums[j];
                count++;
            }
            nums[(i+k)%n]=temp;
            count++;
        }
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4,5,6,7};
    int k=3;
    sol.rotate(nums,k);
    DBGV(nums);

    system("pause");
    return 0;
}
