#include "utils.h"

class Bank {
    int n;
    vector<long long>&balance;
public:
    //本题为简单模拟，只需要检查下标合法性即可
    //注意数组下标基于 0 ，而参数account是基于 1 
    Bank(vector<long long>& balance):balance(balance),n(balance.size()){}
    bool transfer(int account1, int account2, long long money) {
        if(account1<1||account1>n)return false;
        if(account2<1||account2>n)return false;
        if(balance[account1-1]<money)return false;
        balance[account1-1]-=money;
        balance[account2-1]+=money;
        return true;
    }
    bool deposit(int account, long long money) {
        if(account<1||account>n)return false;
        balance[account-1]+=money;
        return true;
    }
    bool withdraw(int account, long long money) {
        if(account<1||account>n)return false;
        if(balance[account-1]<money)return false;
        balance[account-1]-=money;
        return true;
    }
};

int main()
{
    cout<<boolalpha;

    vector<long long>balance{10,100,20,50,30};
	Bank*obj=new Bank(balance);
	obj->withdraw(3,10);
	obj->transfer(5,1,20);
	obj->deposit(5,20);
	obj->transfer(3,4,15);
	obj->withdraw(10,50);

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