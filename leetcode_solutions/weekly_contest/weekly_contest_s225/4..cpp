#include "utils.h"

class Solution {
public:
    int minimumBoxes(int n) {
        //二分确定能够涵盖n个方块的完美三角锥边长
        //体积公式：V=a(a+1)(a+2)/6;
        long low=1,high=min(n,2000);
        while(low<high){
            long mid=(low+high)/2;
            long res=mid*(mid+1)*(mid+2)/6;
            if(res>=n)high=mid;
            else low=mid+1;
        }
        //求得edge即为边长
        long edge=low;
        //考虑到完美三角锥的方块个数>=n个，考虑拆除若干方块
        long all=edge*(edge+1)*(edge+2)/6;
        long bottom=edge*(edge+1)/2;
        //考虑到稳定性，所以只能从上往下拆除
        //经过观察，发现第一次需要拆edge块，才会让底面积减一
        //下一次需要拆edge-1块，才会让底面积减一
        //下一次需要拆edge-2块，才会让底面积减一
        //每次让底面积减一所需的拆除块数为edge,edge-1,edge-2,...
        for(int i=low;i>0;i--){
            //当拆i块还够n个时，继续拆
            if(all-i>=n){
                all-=i;
                bottom--;
            }
            //不够就不拆了
            else break;
        }
        return bottom;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=11;
    auto ans=sol.minimumBoxes(n);
    DBG(ans);

    system("pause");
    return 0;
}
