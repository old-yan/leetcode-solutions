#include "utils.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>S;
        for(int a:nums)S.insert(a);
        int ans=0;
        for(int a:nums){
            if(!S.count(a-1)){
                int i;
                for(i=a;S.count(i);i++);
                chmax(ans,i-a);
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{100,4,200,1,3,2};
    auto ans=sol.longestConsecutive(nums);
    DBG(ans);

    system("pause");
    return 0;
}
