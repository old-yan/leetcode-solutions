#include "SegTree.h"
#include "utils.h"

struct node{
    int a,b;
    node():a(1),b(0){}
    node(int _b):a(1),b(_b){}
    node(int _a,int _b):a(_a),b(_b){}
    node operator+(const node&other)const{
        return node((ll)a*other.a%MOD,((ll)b*other.a+other.b)%MOD);
    }
};
LazyTree<node>T(100000,[](node&x,node&y){return x+y;});
class Fancy {
    int cnt;
public:
    Fancy() {
        cnt=0;
    }
    void append(int val) {
        T.set(cnt++,node(1,val));
    }
    void addAll(int inc) {
        T.step(0,cnt-1,node(1,inc));
    }
    void multAll(int m) {
        T.step(0,cnt-1,node(m,0));
    }
    int getIndex(int idx) {
        if(idx>=cnt)return -1;
        else return T[idx].b;
    }
};

int main()
{
    cout<<boolalpha;

	Fancy*obj=new Fancy();
	obj->append(7);
	obj->append(8);
	obj->append(7);
	obj->append(9);
	obj->append(10);
	obj->append(6);
    obj->append(8);
	obj->addAll(3);
	DBG(obj->getIndex(5));

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