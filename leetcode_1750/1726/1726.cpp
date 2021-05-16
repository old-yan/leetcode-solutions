#include "utils.h"

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>M;
        REP(i,n){
            REP(j,i){
                M[nums[i]*nums[j]]++;
            }
        }
        ll ans=0;
        for(auto&it:M){
            ans+=it.second*(it.second-1)*4;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{2,3,4,6};
    auto ans=sol.tupleSameProduct(nums);
    DBG(ans);

    system("pause");
    return 0;
}
