#include "utils.h"

class Solution {
public:
    //按照题意，进行几次模拟，发现在变换过程中，头尾元素位置不变
    //而中间的元素，如果原下标为 i ，变换一次之后会来到下标 i*2%(n-1)
    //那么，如果变换两次，就会来到下标 i*2*2%(n-1)
    //如果变换 j 次，就会来到下标 i*pow(2,j)%(n-1)
    //要令每个元素各回各家，那就是 i*pow(2,j)%(n-1)=i
    //所以，我们要找出最小的j，令i*(pow(2,j)-1)%(n-1)=0
    //即(pow(2,j)-1)%(n-1)=0，pow(2,j)%(n-1)=1
    int reinitializePermutation(int n) {
        //n=2的情况要特判
        if(n==2)return 1;
        int ans=0,prod=1;
        do{
            ans++;
            prod=prod*2%(n-1);
        }while(prod!=1);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int n=800;
    auto ans=sol.reinitializePermutation(n);
    DBG(ans);

    system("pause");
    return 0;
}
