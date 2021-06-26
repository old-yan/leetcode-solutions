#include "utils.h"

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<ll,int>M;
        for(int a:nums1)M[(ll)a*a]++;
        int ans=0;
        REP(i,nums2.size()){
            REP(j,i){
                ans+=M[(ll)nums2[i]*nums2[j]];
            }
        }
        M.clear();
        for(int a:nums2)M[(ll)a*a]++;
        REP(i,nums1.size()){
            REP(j,i){
                ans+=M[(ll)nums1[i]*nums1[j]];
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{7,4};
    vi nums2{5,2,8,9};
    auto ans=sol.numTriplets(nums1,nums2);
    DBG(ans);

    system("pause");
    return 0;
}
