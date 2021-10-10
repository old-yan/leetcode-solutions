#include "utils.h"

class Solution {
public:
    //简单地统计一下 1~100 的情况就可以了
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        bool appear1[101]={0},appear2[101]={0},appear3[101]={0};
        for(int a:nums1)appear1[a]=true;
        for(int a:nums2)appear2[a]=true;
        for(int a:nums3)appear3[a]=true;
        vector<int>ans;
        for(int i=1;i<=100;i++){
            int appear=appear1[i]+appear2[i]+appear3[i];
            if(appear>=2)ans.push_back(i);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<int>nums1{1,1,3,2};
    vector<int>nums2{2,3};
    vector<int>nums3{3};
    auto ans=sol.twoOutOfThree(nums1,nums2,nums3);
    DBGV(ans);

    system("pause");
    return 0;
}