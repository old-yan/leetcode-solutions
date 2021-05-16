#include "utils.h"

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        multiset<int>S;
        for(int a:nums){
            if(S.count(k-a)){
                S.erase(S.find(k-a));
            }
            else{
                S.insert(a);
            }
        }
        return (nums.size()-S.size())/2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{1,2,3,4};
    int k=5;
    auto ans=sol.maxOperations(nums,k);
    DBG(ans);

    system("pause");
    return 0;
}
