#include "utils.h"

class Solution {
public:
    Solution(vector<int>& nums) {

    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {

    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {

    }
};

int main()
{
    cout<<boolalpha;

    vi nums{1,2,3};
    Solution*obj=new Solution(nums);
	obj->shuffle();
	obj->reset();
	obj->shuffle();

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