#include "SegTree.h"
#include "utils.h"

SegTree<ll>T(100000,[](ll x,ll y){return x+y;});
SegTree<ll>T2(100000,[](ll x,ll y){return x+y;});
class MKAverage {
    queue<int>Q;
    int m,k;
public:
    MKAverage(int _m, int _k):m(_m),k(_k) {
        T.set(0);
        T2.set(0);
    }
    void addElement(int num) {
        Q.push(num);
        T.step_forward(num);
        T2.step(num,num);
        if(Q.size()>m){
            num=Q.front();
            Q.pop();
            T.step_back(num);
            T2.step(num,-num);
        }
    }
    int calculateMKAverage() {
        if(Q.size()<m)return -1;
        ll a=T.find_nth(k);
        ll b=T.find_nth(m-k-1);
        return (T2(a,b)-a*(k-T(0,a-1))-b*(k-T(b+1,100000)))/(m-k*2);
    }
};

int main()
{
    cout<<boolalpha;

	MKAverage*obj=new MKAverage(3,1);
	obj->addElement(17612);
	obj->addElement(74607);
	obj->calculateMKAverage();
	obj->addElement(8272);
	obj->addElement(33433);
	obj->calculateMKAverage();
	obj->addElement(15456);
	obj->addElement(64938);
	obj->calculateMKAverage();
	obj->addElement(99741);

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