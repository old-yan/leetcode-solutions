#include "utils.h"

class Solution {
public:
    //对每一个下标，考虑将其替换之后可以获取的收益。在原答案上，加一个最大收益即可
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int>S(ALL(nums1));
        ll ans=0;
        ll option=0;
        for(int i=0;i<nums1.size();i++){
            //dif表示原差值
            ll dif=abs(nums1[i]-nums2[i]);
            ans+=dif;
            //dif2表示把nums1[i]替换之后，的最小差值。既然差值要最小，就要找个和nums2[i]最接近的替换
            ll dif2;
            auto it=S.lower_bound(nums2[i]);
            if(it==S.end()){
                dif2=abs(nums2[i]-*prev(it));
            }
            else if(it==S.begin()){
                dif2=abs(nums2[i]-*it);
            }
            else{
                dif2=min(abs(nums2[i]-*it),abs(nums2[i]-*prev(it)));
            }
            option=max(option,dif-dif2);
        }
        return (ans-option)%MOD;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{1,10,4,4,2,7};
    vi nums2{9,3,5,1,7,4};
    auto ans=sol.minAbsoluteSumDiff(nums1,nums2);
    DBG(ans);

    system("pause");
    return 0;
}
