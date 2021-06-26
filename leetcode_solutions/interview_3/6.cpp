#include "utils.h"

class AnimalShelf {
    queue<pair<int,int>>cat,dog;
    int timestamp;
public:
    AnimalShelf() :timestamp(0){}
    void enqueue(vector<int> animal) {
        if(animal[1]){
            dog.emplace(animal[0],timestamp++);
        }
        else{
            cat.emplace(animal[0],timestamp++);
        }
    }
    vector<int> dequeueAny() {
        if(cat.empty()&&dog.empty())return {-1,-1};
        if((cat.size()&&dog.empty())||(cat.size()&&dog.size()&&cat.front().second<dog.front().second))return dequeueCat();
        else return dequeueDog();
    }
    vector<int> dequeueDog() {
        if(dog.size()){
            int res=dog.front().first;
            dog.pop();
            return {res,1};
        }
        else return {-1,-1};
    }
    vector<int> dequeueCat() {
        if(cat.size()){
            int res=cat.front().first;
            cat.pop();
            return {res,0};
        }
        else return {-1,-1};
    }
};

int main()
{
    cout<<boolalpha;

	AnimalShelf*obj=new AnimalShelf();
	obj->enqueue({0,0});
	obj->enqueue({1,0});
	obj->dequeueCat();
	obj->dequeueDog();
	obj->dequeueAny();

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