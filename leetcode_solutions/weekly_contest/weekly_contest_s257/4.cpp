#include "utils.h"
#include "Union.h"

Union u(100001);
class Solution {
public:
    //很经典的一道题：无限次数交换，只要两个元素之间能通过并查集搭上关系，那么它们一定可以随便交换
    bool gcdSort(vector<int>& nums) {
        u.reset();
        //枚举所有可能的gcd
        for(int gcd=2;gcd<=100000;gcd++){
            //对每个gcd，枚举包含它的数字，这些数字一定可以被gcd整除
            for(int num=gcd*2;num<=100000;num+=gcd){
                //把这些数字都联通
                u.unite(num,num-gcd);
            }
        }
        vi sorted=nums;
        sort(ALL(sorted));
        //一旦发现sorted和原数组的对应位置的元素不能联通，说明交换不成立
        for(int i=0;i<nums.size();i++){
            if(!u.same(nums[i],sorted[i]))return false;
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi nums{10,5,9,3,15};
    auto ans=sol.gcdSort(nums);
    DBG(ans);

    system("pause");
    return 0;
}
