#include "utils.h"

class SubrectangleQueries {
    vvi&rectangle;
    vector<tuple<int,int,int,int,int>>history;
public:
    SubrectangleQueries(vector<vector<int>>& _rectangle):rectangle(_rectangle) {}
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        history.emplace_back(row1,col1,row2,col2,newValue);
    }
    int getValue(int row, int col) {
        REPR(i,history.size()-1){
            auto [row1,col1,row2,col2,newValue]=history[i];
            if(row>=row1&&row<=row2&&col>=col1&&col<=col2){
                return newValue;
            }
        }
        return rectangle[row][col];
    }
};

int main()
{
    cout<<boolalpha;

    vvi rectangle=makevvi("[[1,2,1,[4,3,4],[3,2,1],[1,1,1]]]");
	SubrectangleQueries*obj=new SubrectangleQueries(rectangle);
	obj->getValue(0,2);
	obj->updateSubrectangle(0,0,3,2,5);
	obj->getValue(0,2);
	obj->getValue(3,1);
	obj->updateSubrectangle(3,0,3,2,10);
	obj->getValue(3,1);
	obj->getValue(0,2);

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