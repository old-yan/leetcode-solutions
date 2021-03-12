#include "utils.h"

class ExamRoom {
    struct range{
        int dis,left,right;
        range(int _dis,int _left,int _right):dis(_dis),left(_left),right(_right){}
        bool operator<(const range&other)const{
            if(dis!=other.dis)return dis>other.dis;
            return left<other.left;
        }
    };
    int N;
    set<range>emptyRanges;
    set<int>seatedPeople;
public:
    ExamRoom(int _N):N(_N){
        insert(0,N-1);
    }
    void insert(int left,int right){
        if(left>right)return;
        if(!left)emptyRanges.emplace(right,0,right);
        else if(right==N-1)emptyRanges.emplace(N-1-left,left,N-1);
        else emptyRanges.emplace((right-left)/2,left,right);
    }
    void erase(int left,int right){
        if(left>right)return;
        if(!left)emptyRanges.erase({right,0,right});
        else if(right==N-1)emptyRanges.erase({N-1-left,left,N-1});
        else emptyRanges.erase({(right-left)/2,left,right});
    }
    int seat() {
        auto [size,left,right]=*emptyRanges.begin();
        emptyRanges.erase(emptyRanges.begin());
        if(!left){
            insert(left+1,right);
            seatedPeople.insert(0);
            return 0;
        }
        else if(right==N-1){
            insert(left,right-1);
            seatedPeople.insert(N-1);
            return N-1;
        }
        else{
            int mid=(left+right)/2;
            insert(left,mid-1);
            insert(mid+1,right);
            seatedPeople.insert(mid);
            return mid;
        }
    }
    void leave(int p) {
        auto it=seatedPeople.lower_bound(p);
        int before=-1,after=N;
        if(it!=seatedPeople.begin())before=*prev(it);
        if(next(it)!=seatedPeople.end())after=*next(it);
        seatedPeople.erase(it);
        erase(before+1,p-1);
        erase(p+1,after-1);
        insert(before+1,after-1);
    }
};

int main()
{
    cout<<boolalpha;

	ExamRoom*obj=new ExamRoom(10);
	obj->seat();
	obj->seat();
	obj->seat();
	obj->seat();
	obj->leave(4);
	obj->seat();

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