#include "SegTree.h"
#include "utils.h"

struct node{
    unsigned short val=0,freq=0;
    node(){}
    node(unsigned short _val,unsigned short _freq=1):val(_val),freq(_freq){}
    node operator+(const node&other)const{
        if(val==other.val)return node(val,freq+other.freq);
        else if(freq<other.freq)return node(other.val,other.freq-freq);
        else return node(val,freq-other.freq);
    }
};
SegTree<node>T(20001,[](node&x,node&y){return x+y;});
class MajorityChecker {
    vector<int> appear[20001];
    int rangeSum(int val,int left,int right){
        return upper_bound(ALL(appear[val]),right)-upper_bound(ALL(appear[val]),left-1);
    }
public:
    MajorityChecker(vector<int>&arr){
        for(int i=0;i<arr.size();i++){
            appear[arr[i]].push_back(i);
        }
        for(T.X=4;T.X<arr.size();T.X<<=1);
        T.set(arr);
    }
    int query(int left, int right, int th) {
        auto res=T(left,right);
        if(rangeSum(res.val,left,right)>=th)return res.val;
        else return -1;
    }
};

int main()
{
    cout<<boolalpha;

    vi arr{1,1,2,2,1,1};
	MajorityChecker*obj=new MajorityChecker(arr);
	obj->query(0,5,4);
    obj->query(0,3,3);
    obj->query(2,3,2);

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