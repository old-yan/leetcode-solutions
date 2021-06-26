#include "utils.h"

class Solution {
public:
    int magicTower(vector<int>& nums) {
        if(1+accumulate(ALL(nums),0ll)<=0)return -1;
        ll cur=1;
        priority_queue<int>Q;
        int ans=0;
        for(int a:nums){
            Q.push(-a);
            cur+=a;
            if(cur<=0){
                ans++;
                cur+=Q.top();
                Q.pop();
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{100,100,100,-250,-60,-140,-50,-50,100,150};
    auto ans=sol.magicTower(nums);
    DBG(ans);

    system("pause");
    return 0;
}
