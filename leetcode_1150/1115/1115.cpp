#include <windows.h>
#include <thread>
#include <semaphore.h>
#include "utils.h"

class FooBar {
private:
    int n;
    sem_t sem1,sem2;
public:
    FooBar(int _n):n(_n) {
        sem_init(&sem1,0,1);
        sem_init(&sem2,0,0);
    }
    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem_wait(&sem1);
        	printFoo();
            sem_post(&sem2);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem_wait(&sem2);
        	printBar();
            sem_post(&sem1);
        }
    }
};

int main()
{
    cout<<boolalpha;

    FooBar *obj=new FooBar(10);

    cout<<"线程1出发，调用bar函数...\n";
    thread t1(&FooBar::bar,obj,[](){printf("bar\n");});
    t1.detach();
    Sleep(1000);

    cout<<"线程2出发，调用foo函数...\n";
    thread t2(&FooBar::foo,obj,[](){printf("foo\n");});
    t2.detach();
    Sleep(1000);

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