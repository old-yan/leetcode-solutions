#include "utils.h"

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1)return 0;
        auto comp=[&](int x,int y){
            return nums[x]>nums[y];
        };
        priority_queue<int,vi,decltype(comp)>Q(comp);
        REP(i,nums.size()){
            Q.push(i);
            if(Q.size()>2)Q.pop();
        }
        int Second=Q.top();
        Q.pop();
        if(nums[Q.top()]>=nums[Second]*2)return Q.top();
        else return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{3,6,1,0};
    auto ans=sol.dominantIndex(nums);
    DBG(ans);

    system("pause");
    return 0;
}
