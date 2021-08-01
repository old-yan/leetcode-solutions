#include "utils.h"

class Solution {
public:
    //本题一看就知道是个二分，难点在于找出面积公式
    long long minimumPerimeter(long long neededApples) {
        //将正方形面积拆成若干个环，每个环的苹果数为 12*a*a
        //百度一个平方和公式：从1到a的平方的和为 a*(a+1)*(a*2+1)/6
        auto area=[](long long a){
            return 2*a*(a+1)*(a*2+1);
        };
        long long low=1,high=100000;
        while(low<high){
            long long mid=(low+high)/2;
            if(area(mid)>=neededApples)high=mid;
            else low=mid+1;
        }
        return low*8;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    long long neededApples=1000000000;
    auto ans=sol.minimumPerimeter(neededApples);
    DBG(ans);

    system("pause");
    return 0;
}
