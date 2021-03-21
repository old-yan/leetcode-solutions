#include "utils.h"

class Solution {
public:
    //二分确定第一个使全数组和超过maxSum的nums[index]的值，减一就是答案
    int maxValue(int n, int index, int maxSum) {
        ll low=0,high=maxSum+1;
        //l1和l2表示从index处往左到头和往右到尾的长度
        int l1=index+1,l2=n-index;
        while(low<high){
            ll mid=(low+high)/2;
            ll sum=0;
            //判断往左能否降到1，根据能否降到1进行不同公式求和
            if(l1<mid){
                sum+=(mid*2-l1+1)*l1/2;
            }
            else{
                sum+=(mid+1)*mid/2+l1-mid;
            }
            //判断往右能否降到1，根据能否降到1进行不同公式求和
            if(l2<mid){
                sum+=(mid*2-l2+1)*l2/2;
            }
            else{
                sum+=(mid+1)*mid/2+l2-mid;
            }
            sum-=mid;
            if(sum>maxSum)high=mid;
            else low=mid+1;
        }
        //找出第一个超标的值之后，减一就是答案
        return low-1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    auto ans=sol.maxValue(1,0,24);
    DBG(ans);

    system("pause");
    return 0;
}
