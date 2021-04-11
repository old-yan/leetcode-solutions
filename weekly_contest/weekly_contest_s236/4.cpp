#include "utils.h"

class MKAverage {
    int m,k;
    vector<int>v;
    multiset<int>S1,S2,S3;
    long long sum=0;
public:
    //用三个multiset，分别保存三个区间内的数
    MKAverage(int _m, int _k):m(_m),k(_k) {}
    //本函数将第一个区间最大值传给第二个区间
    void tobig(multiset<int>&A,multiset<int>&B){
        B.insert(*prev(A.end()));
        A.erase(prev(A.end()));
    }
    //本函数将第一个区间最小值传给第二个区间
    void tosmall(multiset<int>&A,multiset<int>&B){
        B.insert(*A.begin());
        A.erase(A.begin());
    }
    void addElement(int num) {
        v.push_back(num);
        if(S1.size()<k)S1.insert(num);
        else if(S3.size()<k){
            S1.insert(num);
            tobig(S1,S3);
        }
        else{
            S1.insert(num);
            sum+=*prev(S1.end());
            tobig(S1,S2);
            sum-=*prev(S2.end());
            tobig(S2,S3);
            sum+=*S3.begin();
            tosmall(S3,S2);
        }
        if(v.size()<=m)return;
        num=v[v.size()-1-m];
        if(num<=*prev(S1.end())){
            S1.erase(S1.find(num));
            sum-=*S2.begin();
            tosmall(S2,S1);
        }
        else if(num>=*S3.begin()){
            S3.erase(S3.find(num));
            sum-=*prev(S2.end());
            tobig(S2,S3);
        }
        else{
            sum-=num;
            S2.erase(S2.find(num));
        }
    }
    int calculateMKAverage() {
        if(v.size()<m)return -1;
        else return sum/(m-k*2);
    }
};

int main()
{
    cout<<boolalpha;

	MKAverage*obj=new MKAverage(3,1);
	obj->addElement(3);
	obj->addElement(1);
	obj->calculateMKAverage();
	obj->addElement(10);
	obj->calculateMKAverage();
	obj->addElement(5);
	obj->addElement(5);
	obj->addElement(5);
	obj->calculateMKAverage();

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