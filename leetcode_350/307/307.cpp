#include "utils.h"

class NumArray {
    SegTree<int>T;
public:
    NumArray(vector<int>& nums):T(nums,0,[](int x,int y){return x+y;}) {}
    void update(int index, int val) {
        T.set(index,val);
    }
    int sumRange(int left, int right) {
        return T(left,right);
    }
};

int main()
{
    cout<<boolalpha;

    vi nums{7,2,7,2,0};
	NumArray*obj=new NumArray(nums);
	obj->update(4,6);
	obj->update(0,2);
	obj->update(0,9);
	DBG(obj->sumRange(4,4));
	obj->update(3,8);
	DBG(obj->sumRange(0,4));
	obj->update(4,1);
	DBG(obj->sumRange(0,3));
	DBG(obj->sumRange(0,4));
	obj->update(0,4);

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