#include "utils.h"

class Solution {
    double r,x,y;
public:
    Solution(double radius, double x_center, double y_center):r(radius),x(x_center),y(y_center) {}
    vector<double> randPoint() {
        double alpha=2*PI*(double(rand())/RAND_MAX);
        double rr=r*sqrt(double(rand())/RAND_MAX);
        return {x+rr*cos(alpha),y+rr*sin(alpha)};
    }
};

int main()
{
    cout<<boolalpha;

	Solution*obj=new Solution(1.0, 0.0, 0.0);
	DBGV(obj->randPoint());
    DBGV(obj->randPoint());
    DBGV(obj->randPoint());
    DBGV(obj->randPoint());
    DBGV(obj->randPoint());
    DBGV(obj->randPoint());

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