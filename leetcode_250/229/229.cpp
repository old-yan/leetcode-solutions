#include "utils.h"

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a,na=0,b,nb=0;
        for(int x:nums){
            if(x==a){
                na++;
            }
            else if(x==b){
                nb++;
            }
            else if(!na){
                a=x;
                na=1;
            }
            else if(!nb){
                b=x;
                nb=1;
            }
            else{
                na--;
                nb--;
            }
        }
        na=nb=0;
        for(int x:nums){
            if(x==a)na++;
            else if(x==b)nb++;
        }
        vi ans;
        if(na>nums.size()/3)ans.pb(a);
        if(nb>nums.size()/3)ans.pb(b);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,1,1,3,3,2,2,2};
    auto ans=sol.majorityElement(nums);
    DBGV(ans);

    system("pause");
    return 0;
}
