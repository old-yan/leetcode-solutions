#include <windows.h>
#include <thread>
#include <semaphore.h>
#include "utils.h"

sem_t fork[5],food[5];
vi cnt(5,0);
auto _initial=[](){
    REP(i,5){
        sem_init(fork+i,0,1);
        sem_init(food+i,0,1);
    }
    return 0;
}();

class DiningPhilosophers {
    sem_t sem[5];
public:
    DiningPhilosophers() {
        REP(i,5){
            sem_init(sem+i,0,1);
        }
    }
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        if(philosopher>2){
            sem_wait(sem+philosopher-1);
            pickRightFork();
            sem_wait(sem+philosopher);
            pickLeftFork();
            eat();
            putLeftFork();
            sem_post(sem+philosopher);
            putRightFork();
            sem_post(sem+philosopher-1);
        }
        else{
            sem_wait(sem+philosopher);
            pickLeftFork();
            sem_wait(sem+(philosopher+4)%5);
            pickRightFork();
            eat();
            putRightFork();
            sem_post(sem+(philosopher+4)%5);
            putLeftFork();
            sem_post(sem+philosopher);
        }
    }
};

int main()
{
    cout<<boolalpha;

    DiningPhilosophers *obj=new DiningPhilosophers();

    int n=5;
    string s="01234",ss;
    while(n--)ss+=s;
    random_shuffle(ALL(ss));
    DBG(ss);
    for(char c:ss){
        int cur=c-'0';
        thread t(&DiningPhilosophers::wantsToEat,obj,cur,
                        [=](){
                            sem_wait(fork+cur);
                            printf("%d pick left:%d\n",cur,cur);
                        },
                        [=](){
                            sem_wait(fork+(cur+4)%5);
                            printf("%d pick right:%d\n",cur,(cur+4)%5);
                        },
                        [=](){
                            sem_wait(food+cur);
                            printf("%d eat\n",cur);
                            cnt[cur]++;
                            sem_post(food+cur);
                        },
                        [=](){
                            sem_post(fork+cur);
                            printf("%d put left:%d\n",cur,cur);
                        },
                        [=](){
                            sem_post(fork+(cur+4)%5);
                            printf("%d put right:%d\n",cur,(cur+4)%5);
                        });
        t.detach();
    }

    Sleep(1000);
    DBGV(cnt);
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