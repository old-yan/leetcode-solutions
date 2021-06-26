#include <windows.h>
#include <thread>
#include <semaphore.h>
#include "utils.h"

class FizzBuzz {
private:
    int n;
    int cur;
    sem_t sem_35,sem_3,sem_5,sem_1;
public:
    FizzBuzz(int _n):n(_n),cur(0) {
        sem_init(&sem_35,0,1);
        sem_init(&sem_3,0,0);
        sem_init(&sem_5,0,0);
        sem_init(&sem_1,0,0);
    }
    void fizz(function<void()> printFizz) {
        while(true){
            sem_wait(&sem_3);
            if(cur>n)return;
            if(cur%3==0){
                printFizz();
                sem_post(&sem_35);
            }
            else{
                sem_post(&sem_5);
            }
        }
    }
    void buzz(function<void()> printBuzz) {
        while(true){
            sem_wait(&sem_5);
            if(cur>n)return;
            if(cur%5==0){
                printBuzz();
                sem_post(&sem_35);
            }
            else{
                sem_post(&sem_1);
            }
        }
    }
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            sem_wait(&sem_35);
            if(++cur>n){
                sem_post(&sem_3);
                sem_post(&sem_5);
                sem_post(&sem_1);
                return;
            }
            else{
                if(cur%15==0){
                    printFizzBuzz();
                    sem_post(&sem_35);
                }
                else sem_post(&sem_3);
            }
        }
    }
    void number(function<void(int)> printNumber) {
        while(true){
            sem_wait(&sem_1);
            if(cur>n)return;
            printNumber(cur);
            sem_post(&sem_35);
        }
    }
};

int main()
{
    cout<<boolalpha;

    FizzBuzz *obj=new FizzBuzz(30);

    cout<<"线程1出发，调用buzz函数...\n";
    thread t1(&FizzBuzz::buzz,obj,[](){
        printf("buzz\n");
        Sleep(1);
    });
    t1.detach();

    cout<<"线程2出发，调用fizz函数...\n";
    thread t2(&FizzBuzz::fizz,obj,[](){
        printf("fizz\n");
        Sleep(1);
    });
    t2.detach();

    cout<<"线程3出发，调用fizzbuzz函数...\n";
    thread t3(&FizzBuzz::fizzbuzz,obj,[](){
        printf("fizzbuzz\n");
        Sleep(1);
    });
    t3.detach();

    cout<<"线程4出发，调用输出函数...\n";
    thread t4(&FizzBuzz::number,obj,[](int x){
        printf("%d\n",x);
        Sleep(1);
    });
    t4.detach();

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