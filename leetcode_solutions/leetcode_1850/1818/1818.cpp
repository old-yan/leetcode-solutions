#include "utils.h"

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        ll dif=0;
        REP(i,n){
            dif+=abs(nums1[i]-nums2[i]);
        }
        int makeup=0;
        set<int>S(ALL(nums1));
        REP(i,n){
            auto it=S.lower_bound(nums2[i]);
            if(it!=S.end())chmax(makeup,abs(nums1[i]-nums2[i])-abs(*it-nums2[i]));
            if(it!=S.begin()){
                --it;
                chmax(makeup,abs(nums1[i]-nums2[i])-abs(*it-nums2[i]));
            }
        }
        return (dif-makeup)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{1,7,5};
    vi nums2{2,3,5};
    auto ans=sol.minAbsoluteSumDiff(nums1,nums2);
    DBG(ans);

    system("pause");
    return 0;
}
