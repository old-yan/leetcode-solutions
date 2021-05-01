#include "utils.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        deque<int>Qmin,Qmax;
        int pre=-1;
        int ans=0;
        REP(i,nums.size()){
            while(Qmin.size()&&nums[Qmin.back()]>=nums[i])Qmin.pop_back();
            Qmin.pb(i);
            while(Qmax.size()&&nums[Qmax.back()]<=nums[i])Qmax.pop_back();
            Qmax.pb(i);
            while(nums[Qmax.front()]-nums[Qmin.front()]>limit){
                if(Qmax.front()<Qmin.front()){
                    pre=Qmax.front();
                    Qmax.pop_front();
                }
                else{
                    pre=Qmin.front();
                    Qmin.pop_front();
                }
            }
            chmax(ans,int(i)-pre);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{8,2,4,7};
    int limit=4;
    auto ans=sol.longestSubarray(nums,limit);
    DBG(ans);

    system("pause");
    return 0;
}
