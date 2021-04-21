#include "SegTree.h"
#include "utils.h"

SegTree<int>T(20001,[](int x,int y){return x+y;});
class Skiplist {
public:
    Skiplist() {
        T.set(0);
    }
    bool search(int target) {
        return T[target]>0;
    }
    void add(int num) {
        T.step_forward(num);
    }
    bool erase(int num) {
        if(T[num]){
            T.step_back(num);
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{
    cout<<boolalpha;

	Skiplist*obj=new Skiplist();
	obj->add(1);
	obj->add(2);
	obj->add(3);
	obj->search(0);
	obj->add(4);
	obj->search(1);
	obj->erase(0);
	obj->erase(1);
	obj->search(1);

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