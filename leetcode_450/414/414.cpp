#include "utils.h"

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        ll First=LLONG_MIN;
        for(int a:nums)chmax(First,(ll)a);
        ll Second=LLONG_MIN;
        for(int a:nums){
            if(a!=First){
                chmax(Second,(ll)a);
            }
        }
        if(Second==LLONG_MIN)return First;
        ll Third=LLONG_MIN;
        for(int a:nums){
            if(a!=First&&a!=Second){
                chmax(Third,(ll)a);
            }
        }
        if(Third==LLONG_MIN)return First;
        else return Third;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,2,3,1};
    auto ans=sol.thirdMax(nums);
    DBG(ans);

    system("pause");
    return 0;
}
