#include "utils.h"

class RLEIterator {
    vector<int>*origin;
    int cur;
public:
    RLEIterator(vector<int>& A):origin(&A),cur(0) {}
    int next(int n) {
        while(cur<origin->size()&&(*origin)[cur]<n){
            n-=(*origin)[cur];
            cur+=2;
        }
        if(cur==origin->size())return -1;
        else{
            (*origin)[cur]-=n;
            return (*origin)[cur+1];
        }
    }
};

int main()
{
    cout<<boolalpha;

	RLEIterator*obj=new RLEIterator([3,8,0,9,2,5);
	obj->next(2);
	obj->next(1);
	obj->next(1);
	obj->next(2);

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