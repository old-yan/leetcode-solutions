#include "utils.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int>S;
        for(int a:nums1)S.insert(a);
        vi ans;
        for(int a:nums2){
            if(S.count(a)){
                ans.pb(a);
                S.erase(S.find(a));
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{4,9,5};
    vi nums2{9,4,9,8,4};
    auto ans=sol.intersect(nums1,nums2);
    DBGV(ans);

    system("pause");
    return 0;
}
