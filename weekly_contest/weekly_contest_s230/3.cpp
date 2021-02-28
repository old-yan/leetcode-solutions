#include "utils.h"

class Solution {
public:
    //可以暴力模拟一遍
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        //先算出两个数组的和
        int sum1=accumulate(ALL(nums1),0);
        int sum2=accumulate(ALL(nums2),0);
        if(sum1==sum2)return 0;
        //将每个数字可以弥合的差距送入大根堆
        priority_queue<int>Q;
        for(int a:nums1){
            if(sum1<sum2)Q.push(6-a);
            else Q.push(a-1);
        }
        for(int a:nums2){
            if(sum1<sum2)Q.push(a-1);
            else Q.push(6-a);
        }
        int dif=abs(sum1-sum2);
        int step=0;
        while(Q.size()){
            dif-=Q.top();
            Q.pop();
            step++;
            //当弥合差距时，返回步数
            if(dif<=0)return step;
        }
        //如果不能弥合，返回-1
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    

    system("pause");
    return 0;
}
