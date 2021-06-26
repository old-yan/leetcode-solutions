#include <windows.h>
#include <thread>
#include <semaphore.h>
#include "utils.h"

class ZeroEvenOdd {
private:
    int n;
    sem_t sem0,sem1,sem2;
public:
    ZeroEvenOdd(int _n):n(_n) {
        sem_init(&sem0,0,1);
        sem_init(&sem1,0,0);
        sem_init(&sem2,0,0);
    }
    void zero(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++){
            sem_wait(&sem0);
            printNumber(0);
            sem_post(i%2?&sem1:&sem2);
        }
    }
    void even(function<void(int)> printNumber) {
        for(int i=2;i<=n;i+=2){
            sem_wait(&sem2);
            printNumber(i);
            sem_post(&sem0);
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1;i<=n;i+=2){
            sem_wait(&sem1);
            printNumber(i);
            sem_post(&sem0);
        }
    }
};

int main()
{
    cout<<boolalpha;

    ZeroEvenOdd *obj=new ZeroEvenOdd(10);

    cout<<"线程1出发，调用odd函数...\n";
    thread t1(&ZeroEvenOdd::odd,obj,[](int x){
        printf("%d\n",x);
        Sleep(1);
    });
    t1.detach();

    cout<<"线程2出发，调用even函数...\n";
    thread t2(&ZeroEvenOdd::even,obj,[](int x){
        printf("%d\n",x);
        Sleep(1);
    });
    t2.detach();

    cout<<"线程3出发，调用zero函数...\n";
    thread t3(&ZeroEvenOdd::zero,obj,[](int x){
        printf("%d\n",x);
        Sleep(1);
    });
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