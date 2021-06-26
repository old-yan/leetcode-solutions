#include "utils.h"

class SnapshotArray {
    vector<pair<int,int>> v[50000];
    int cur;
public:
    SnapshotArray(int length):cur(0) {}
    void set(int index, int val) {
        if(v[index].empty())v[index].emplace_back(0,0);
        if(v[index].back().first<cur)v[index].emplace_back(cur,val);
        else v[index].back().second=val;
    }
    int snap() {
        cur++;
    }
    int get(int index, int snap_id) {
        int low=0,high=v[index].size()-1;
        while(low<high){
            int mid=(low+high+1)/2;
            if(v[index][mid].first<=snap_id)low=mid;
            else high=mid-1;
        }
        return v[index][low].second;
    }
};

int main()
{
    cout<<boolalpha;

	SnapshotArray*obj=new SnapshotArray(3);
	obj->set(0,5);
	obj->snap();
	obj->set(0,6);
	obj->get(0,0);

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