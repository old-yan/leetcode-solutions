#include "utils.h"

class SORTracker {
    struct node{
        int score;
        string name;
        bool operator<(const node&other)const{
            return score<other.score or (score==other.score and name>other.name);
        }
        bool operator>(const node&other)const{
            return score>other.score or (score==other.score and name<other.name);
        }
    };
    //坏班是大顶堆，时刻准备把尖子送上去
    priority_queue<node>bad;
    //好班是小顶堆，时刻准备把尾巴淘汰
    priority_queue<node,vector<node>,greater<node>>good;
public:
    //注意到查询的单调性，我们可以这样建模：
    //  有个学校，有个好班和差班
    //  调用 add 方法相当于学校招收一个学生，但是不改变好班的人数
    //  调用 get 方法相当于学校将一个坏班学生升到好班里
    SORTracker() {}
    //要想实现招收学生，但不改变好班人数，那肯定要把新生送到坏班。
    //但是有个问题，这个新生万一实力很强呢？那岂不是得升到好班，再把好班淘汰一个到坏班
    //所以我们不管三七二十一，先把新生送到好班去，再淘汰一个送到坏班，这样最方便了
    void add(string name, int score) {
        good.push({score,name});
        bad.push(good.top());
        good.pop();
    }
    //把坏班的第一名送到好班去
    string get() {
        auto ans=bad.top().name;
        good.push(bad.top());
        bad.pop();
        return ans;
    }
};

int main()
{
    cout<<boolalpha;

	SORTracker*obj=new SORTracker();
	obj->add("bradford",2);
	obj->add("branford",3);
	obj->get();
	obj->add("alps",2);
	obj->get();
	obj->add("orland",2);
	obj->get();
	obj->add("orlando",3);
	obj->get();
	obj->add("alpine",2);
	obj->get();
	obj->get();

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