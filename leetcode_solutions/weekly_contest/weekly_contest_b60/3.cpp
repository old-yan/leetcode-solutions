#include "utils.h"

class LockingTree {
    int n;
    //child[i]存放结点i的孩子们
    vi child[2000];
    //locker[i]表示结点i现在被谁锁住，如果值为1说明没被锁住
    int locker[2000];
public:
    LockingTree(vector<int>& parent) {
        n=parent.size();
        for(int i=0;i<n;i++)child[parent[i]].push_back(i);
        for(int i=0;i<n;i++)locker[i]=-1;
    }
    //检查，如果已上锁，那么本次上锁失败；否则成功  
    bool lock(int num, int user) {
        if(locker[num]>=0)return false;
        else locker[num]=user;return true;
    }
    //检查，如果未上锁或者不是被user上锁，那么本次解锁失败；否则成功
    bool unlock(int num, int user) {
        if(locker[num]!=user)return false;
        else locker[num]=-1;return true;
    }
    //从三方面去做检查
    bool upgrade(int num, int user) {
        //如果num已上锁，那么无法升级
        if(locker[num]>=0)return false;
        //写个find_num函数，从根递归地去找num，看能不能找到num
        //途中遇到上锁的就停下来，不往下递归
        function<bool(int)>find_num=[&](int cur){
            if(cur==num)return true;
            else if(locker[cur]>=0)return false;
            else{
                for(int s:child[cur])if(find_num(s))return true;
                return false;
            }
        };
        //如果找不到num，那么说明num的某个祖宗被锁，无法升级
        if(!find_num(0))return false;
        //写个check_children函数，从num递归地去找上锁的子孙，看能不能找到
        //因为这已经是最后一个条件了，只要满足，肯定能升级
        //所以只要碰到一个上锁的子孙，直接给他开锁
        function<bool(int)>check_children=[&](int cur){
            bool flag=false;
            if(locker[cur]>=0){
                flag=true;
                locker[cur]=-1;
            }
            for(int s:child[cur])if(check_children(s))flag=true;
            return flag;
        };
        //如果找不到上锁的子孙，那么升级失败，否则成功
        if(!check_children(num))return false;
        else locker[num]=user;return true;
    }
};

int main()
{
    cout<<boolalpha;

    vi parent{-1,0,0,1,1,2,2};
	LockingTree*obj=new LockingTree(parent);
	obj->lock(2,2);
	obj->unlock(2,3);
	obj->unlock(2,2);
	obj->lock(4,5);
	obj->upgrade(0,1);
	obj->lock(0,1);

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