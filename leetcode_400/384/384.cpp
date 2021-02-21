#include "utils.h"

class Solution {
    vi nums;
    vi*original;
public:
    Solution(vector<int>&_nums):nums(_nums),original(&_nums){}
    vector<int> reset() {
        return *original;
    }
    vector<int> shuffle() {
        REP(i,nums.size()-1){
            swap(nums[i],nums[i+rand()%(nums.size()-i)]);
        }
        return nums;
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