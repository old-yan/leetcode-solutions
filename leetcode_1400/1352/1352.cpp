#include "SegTree.h"
#include "utils.h"

SegTree<int>T(40000,[](int x,int y){
    return min((ll)x*y,(ll)INT_MAX);
});
class ProductOfNumbers {
    int cur;
public:
    ProductOfNumbers() {
        T.set(1);
        cur=0;
    }
    void add(int num) {
        T.set(cur++,num);
    }
    int getProduct(int k) {
        return T(cur-k,cur-1);
    }
};

int main()
{
    cout<<boolalpha;

	ProductOfNumbers*obj=new ProductOfNumbers();
	obj->add(3);
	obj->add(0);
	obj->add(2);
	obj->add(5);
	obj->add(4);
	obj->getProduct(2);
	obj->getProduct(3);
	obj->getProduct(4);
	obj->add(8);
	obj->getProduct(2);

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