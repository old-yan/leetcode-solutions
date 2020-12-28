#include "utils.h"

class BSTIterator {
    stack<TreeNode*>S;
public:
    BSTIterator(TreeNode* root) {
        DBGT(root);
        for(TreeNode*p=root;p;p=p->left)S.push(p);
    }
    
    int next() {
        TreeNode*next=S.top();
        S.pop();
        for(TreeNode*p=next->right;p;p=p->left)S.push(p);
        DBG(next->val);
        return next->val;
    }
    
    bool hasNext() {
        bool hasnext=S.size();
        DBG(hasnext);
        return hasnext;
    }
};

int main()
{
    cout<<boolalpha;

    //由于初始化参数比较复杂，所以初始化代码需要手打
    BSTIterator*obj=new BSTIterator(new TreeNode("7,3,15,null,null,9,20"));
    //后续代码仍然可以使用正则表达式生成
    obj->next();
	obj->next();
	obj->hasNext();
	obj->next();
	obj->hasNext();
	obj->next();
	obj->hasNext();
	obj->next();
	obj->hasNext();

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