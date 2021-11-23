#include "utils.h"

class Robot {
    int w;
    int h;
    int C;
    int cur;
public:
    //本题在比赛中简单起见可以直接模拟。
    //更好的做法是计算所在位置，直接报出位置和方向
    //不难发现，一圈总共 (w+h)*2-4 个点，我们不妨把初始点编号为 0，之后的依次加一
    //那么：
    //  0~w-1 位于最下面一行
    //  w-1~w+h-2 位于最右面一列
    //  w+h-2~w*2+h-3 位于最上面一行
    //  w*2+h-3~w*2+h*2-4 位于最左面一列
    //而 w*2+h*2-4 在取模后也变回了 0
    Robot(int width, int height) {
        w=width;
        h=height;
        C=(w+h)*2-4;
        cur=0;
    }
    void step(int num) {
        cur+=num;
    }
    vector<int> getPos() {
        if(cur%C<w-1)return {cur%C,0};
        else if(cur%C<w+h-2)return {w-1,cur%C-w+1};
        else if(cur%C<w*2+h-3)return {w-1-cur%C+w+h-2,h-1};
        else return {0,h-1-cur%C+w*2+h-3};
    }
    string getDir() {
        if(!cur)return "East";
        else if(cur%C==0)return "South";
        else if(cur%C<=w-1)return "East";
        else if(cur%C<=w+h-2)return "North";
        else if(cur%C<=w*2+h-3)return "West";
        else return "South";
    }
};

int main()
{
    cout<<boolalpha;

	Robot*obj=new Robot(6,3);
	obj->step(2);
	obj->step(2);
	obj->getPos();
	obj->getDir();
	obj->step(2);
	obj->step(1);
	obj->step(4);
	obj->getPos();
	obj->getDir();

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