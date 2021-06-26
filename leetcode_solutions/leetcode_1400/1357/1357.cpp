#include "utils.h"

class Cashier {
    int M[201];
    int n,discount,count;
public:
    Cashier(int _n, int _discount, vector<int>& products, vector<int>& prices):n(_n),count(0),discount(_discount) {
        REP(i,products.size()){
            M[products[i]]=prices[i];
        }
    }
    double getBill(vector<int> product, vector<int> amount) {
        bool b=false;
        if(++count==n){
            count=0;
            b=true;
        }
        double sum=0;
        REP(i,product.size()){
            sum+=b?M[product[i]]*amount[i]*(1-discount/100.0):M[product[i]]*amount[i];
        }
        return sum;
    }
};

int main()
{
    cout<<boolalpha;

    vi products{1,2,3,4,5,6,7};
    vi prices{100,200,300,400,300,200,100};
	Cashier*obj=new Cashier(3,50,products,prices);
	obj->getBill({1,2},{1,2});
    obj->getBill({3,7},{10,10});
    obj->getBill({1,2,3,4,5,6,7},{1,1,1,1,1,1,1});
    obj->getBill({4},{10});
    obj->getBill({7,3},{10,10});
    obj->getBill({7,5,3,1,6,4,2},{10,10,10,9,9,9,7});
    obj->getBill({2,3,5},{5,3,2});

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