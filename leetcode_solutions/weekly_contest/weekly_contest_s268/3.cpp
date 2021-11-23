#include "utils.h"

class RangeFreqQuery {
    vector<int>appear[10001];
public:
    //本题方法众多，进可以使用优化版的二维数组->线段树，退可以使用二分做差
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            appear[arr[i]].push_back(i);
        }
    }
    //本函数二分计算 value 在 arr[:index] 出现了多少次
    int appear_before(int index,int value){
        auto&v=appear[value];
        return lower_bound(v.begin(),v.end(),index)-v.begin();
    }
    //有了 appear_before ，那 query 就很好算了
    int query(int left, int right, int value) {
        return appear_before(right+1,value)-appear_before(left,value);
    }
};

int main()
{
    cout<<boolalpha;

    vector<int>arr{12,33,4,56,22,2,34,33,22,12,34,56};
	RangeFreqQuery*obj=new RangeFreqQuery(arr);
	obj->query(1,2,4);
	obj->query(0,11,33);

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