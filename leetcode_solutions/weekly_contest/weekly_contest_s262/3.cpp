#include "utils.h"

class StockPrice {
    //这个 multiset 用来维护有序的价格
    multiset<int>prices;
    //这个 map 用来维护 时间-价格 的有序映射
    map<int,int>table;
public:
    //本题考查 stl 容器的熟练使用
    StockPrice() {}
    void update(int timestamp, int price) {
        //如果是 更新 而非 新增，那么就要把旧项目删掉
        if(table.count(timestamp)){
            prices.erase(prices.find(table[timestamp]));
        }
        prices.insert(price);
        table[timestamp]=price;
    }
    int current() {
        return table.rbegin()->second;
    }
    int maximum() {
        return *prices.rbegin();
    }
    int minimum() {
        return *prices.begin();
    }
};

int main()
{
    cout<<boolalpha;

	StockPrice*obj=new StockPrice();
	obj->update(1,10);
	obj->update(2,5);
	obj->current();
	obj->maximum();
	obj->update(1,3);
	obj->maximum();
	obj->update(4,2);
	obj->minimum();

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