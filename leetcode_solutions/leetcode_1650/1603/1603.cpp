#include "utils.h"

class ParkingSystem {
    int cap[4]={0};
public:
    ParkingSystem(int big, int medium, int small) {
        cap[1]=big;
        cap[2]=medium;
        cap[3]=small;
    }
    bool addCar(int carType) {
        return cap[carType]-->0;
    }
};

int main()
{
    cout<<boolalpha;

	ParkingSystem*obj=new ParkingSystem(1,1,0);
	obj->addCar(1);
	obj->addCar(2);
	obj->addCar(3);
	obj->addCar(1);

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