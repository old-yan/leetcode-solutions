#include "utils.h"

class Solution {
public:
    //贪心选取
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        //先排序
        sort(ALL(arr));
        //pre记录上一个数字的大小
        int pre=0;
        //遍历数组
        for(int cur:arr){
            //如果当前数字太大，就把它缩小一些
            //可以缩小到pre-1,pre,pre+1
            //因为结果要最大，所以缩小到pre+1即可
            if(cur>pre+1)cur=pre+1;
            pre=cur;
        }
        return pre;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    

    system("pause");
    return 0;
}
