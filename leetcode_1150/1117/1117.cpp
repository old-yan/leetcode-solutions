#include <windows.h>
#include <thread>
#include <semaphore.h>
#include <random>
#include "utils.h"

class H2O {
    sem_t h_come,o_come,h1_out,h2_out,o_out;
    int h;
public:
    H2O():h(0){
        sem_init(&h_come,0,1);
        sem_init(&o_come,0,0);
        sem_init(&h1_out,0,0);
        sem_init(&h2_out,0,0);
        sem_init(&o_out,0,0);
    }
    void hydrogen(function<void()> releaseOxygen) {
        sem_wait(&h_come);
        if(!h++){
            sem_post(&h_come);
            sem_wait(&h1_out);
            releaseOxygen();
            sem_post(&h2_out);
        }
        else{
            sem_post(&o_come);
            sem_wait(&h2_out);
            releaseOxygen();
            sem_post(&o_out);
        }
    }
    void oxygen(function<void()> releaseHydrogen) {
        sem_wait(&o_come);
        sem_post(&h1_out);
        sem_wait(&o_out);
        releaseHydrogen();
        h=0;
        sem_post(&h_come);
    }
};

int main()
{
    cout<<boolalpha;

    H2O *obj=new H2O();

    string task="hhhhhhhhhhhhhhhhhhhhoooooooooo";
    random_shuffle(ALL(task));
    DBG(task);
    REP(i,30){
        if(task[i]=='h'){
            thread t(&H2O::hydrogen,obj,[](){printf("H");});
            t.detach();
        }
        else{
            thread t(&H2O::oxygen,obj,[](){printf("O\n");});
            t.detach();
        }
        Sleep(100);
    }

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