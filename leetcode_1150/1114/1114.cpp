#include <windows.h>
#include <thread>
#include <semaphore.h>
#include "utils.h"

class Foo {
    sem_t sem1,sem2;
public:
    Foo(){
        sem_init(&sem1,0,0);
        sem_init(&sem2,0,0);
    }
    void first(function<void()> printFirst) {
        printFirst();
        sem_post(&sem1);
    }
    void second(function<void()> printSecond) {
        sem_wait(&sem1);
        printSecond();
        sem_post(&sem2);
    }
    void third(function<void()> printThird) {
        sem_wait(&sem2);
        printThird();
    }
};

int main()
{
    cout<<boolalpha;

    Foo *obj=new Foo();
    
    cout<<"线程1出发，调用second函数...\n";
    thread t1(&Foo::second,obj,[](){printf("second\n");});
    t1.detach();
    Sleep(1000);

    cout<<"线程2出发，调用first函数...\n";
    thread t2(&Foo::first,obj,[](){printf("first\n");});
    t2.detach();
    Sleep(1000);

    cout<<"线程3出发，调用third函数...\n";
    thread t3(&Foo::third,obj,[](){printf("third\n");});
    t3.detach();
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