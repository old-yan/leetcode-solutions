#include "utils.h"

class NumArray {
    vi sum;
public:
    NumArray(vector<int>& nums) {
        partial_sum(ALL(nums),nums.begin());
        sum=nums;
    }
    
    int sumRange(int i, int j) {
        return i?sum[j]-sum[i-1]:sum[j];
    }
};

int main()
{
    cout<<boolalpha;

    NumArray*obj=new NumArray({-2, 0, 3, -5, 2, -1});
	DBG(obj->sumRange(0, 2));
	DBG(obj->sumRange(2, 5));
	DBG(obj->sumRange(0, 5));

    system("pause");
    return 0;
}
/*
使用如下正则替换将leetcode测试用例转换为代码
首先将leetcode测试样例复制到代码正文中，把换行符删除，两行合并为一行;
将如下替换使用一次(也可以自己手打)：

\["(.+?)"(.*?)\]\[\[(.*?)\](.*)\]
\t$1*obj=new $1($3);\n[$2][$4]

将如下替换连续使用：

\[,"(.+?)"(.*?)\]\[,\[(.*?)\](.*)\]
\tobj->$1($3);\n[$2][$4]

*/