#include "utils.h"

class SummaryRanges {
    list<vi>L;
public:
    SummaryRanges() {}
    void addNum(int val) {
        auto it=L.begin();
        while(it!=L.end()&&(*it)[1]<val-1)++it;
        if(it==L.end()||(*it)[0]>val+1)L.emplace(it,2,val);
        else{
            auto it2=next(it);
            if(it2==L.end()||(*it2)[0]>val+1){
                chmin((*it)[0],val);
                chmax((*it)[1],val);
            }
            else{
                (*it)[1]=(*it2)[1];
                L.erase(it2);
            }
        }
    }
    vector<vector<int>> getIntervals() {
        vvi ans(ALL(L));
        DBGVV(ans);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;

    SummaryRanges*obj=new SummaryRanges();
	obj->addNum(1);
	obj->getIntervals();
	obj->addNum(3);
	obj->getIntervals();
	obj->addNum(7);
	obj->getIntervals();
	obj->addNum(2);
	obj->getIntervals();
	obj->addNum(6);
	obj->getIntervals();

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