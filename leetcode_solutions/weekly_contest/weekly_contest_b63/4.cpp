#include "utils.h"

class Solution {
    using ll=long long;
public:
    //这道题数据范围很大，所以肯定需要二分
    //对二分的mid，对每个 nums1 里的数，判断其在 nums2 里可以取多少个伙伴，使乘积小于等于mid，如果伙伴总数达到了k说明答案肯定在mid以内
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        //先把正、负、零都统计一下
        vector<int>pos1,neg1,pos2,neg2;
        int zero1=0,zero2=0;
        for(int a:nums1){
            if(a>0)pos1.push_back(a);
            else if(a<0)neg1.push_back(a);
            else zero1++;
        }
        for(int a:nums2){
            if(a>0)pos2.push_back(a);
            else if(a<0)neg2.push_back(a);
            else zero2++;
        }
        ll low=-1e10,high=1e10;
        while(low<high){
            ll mid=low+(high-low)/2;
            ll below_mid=0;
            //使用双指针方法获取乘积在mid以下的配对数
            if(mid>=0){
                //所有含零配对
                below_mid+=zero1*nums2.size()+zero2*nums1.size()-1ll*zero1*zero2;
                //所有负配对
                below_mid+=pos1.size()*neg2.size()+pos2.size()*neg1.size();
                //正配对需要双指针方法
                //对于pos1,要取pos2作为正配对，而且可配对区间是个越来越小的前缀区间
                int l=0,r=pos2.size()-1;
                for(int a:pos1){
                    while(r>=0&&1ll*a*pos2[r]>mid)r--;
                    below_mid+=r-l+1;
                }
                //对于neg1,要取neg2作为正配对，而且可配对区间是个越来越大的后缀区间
                l=neg2.size(),r=neg2.size()-1;
                for(int a:neg1){
                    while(l-1>=0&&1ll*a*neg2[l-1]<=mid)l--;
                    below_mid+=r-l+1;
                }
            }
            else{
                //mid<0时，只考虑负配对
                //对于pos1,要取neg2作为正配对，而且可配对区间是个越来越大的前缀区间
                int l=0,r=-1;
                for(int a:pos1){
                    while(r+1<neg2.size()&&1ll*a*neg2[r+1]<=mid)r++;
                    below_mid+=r-l+1;
                }
                //对于neg1,要取pos2作为正配对，而且可配对区间是个越来越小的后缀区间
                l=0,r=pos2.size()-1;
                for(int a:neg1){
                    while(l<=r&&1ll*a*pos2[l]>mid)l++;
                    below_mid+=r-l+1;
                }
            }
            //根据小于等于mid的配对数，决定二分方向
            if(below_mid>=k)high=mid;
            else low=mid+1;
        }
        return low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums1{-6};
    vi nums2{-9};
    long long k=3;
    auto ans=sol.kthSmallestProduct(nums1,nums2,k);
    DBG(ans);

    system("pause");
    return 0;
}