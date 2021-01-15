#include "utils.h"

class Solution {
    zkwTree T;
    int totalPoints;
    vvi&rects;
public:
    Solution(vector<vector<int>>&_rects):T(_rects.size()),totalPoints(0),rects(_rects) {
        REP(i,rects.size()){
            auto&A=rects[i];
            int x1=A[0],y1=A[1],x2=A[2],y2=A[3];
            int area=(x2-x1+1)*(y2-y1+1);
            T.set(i,area);
            totalPoints+=area;
        }
    }
    vector<int> pick() {
        int idx=T.find_nth(rand()%totalPoints);
        auto&A=rects[idx];
        int x1=A[0],y1=A[1],x2=A[2],y2=A[3];
        return {x1+rand()%(x2-x1+1),y1+rand()%(y2-y1+1)};
    }
};

int main()
{
    cout<<boolalpha;

    vvi rects{
        {1,1,5,5}
    };
	Solution*obj=new Solution(rects);
	obj->pick();
	obj->pick();
	obj->pick();

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