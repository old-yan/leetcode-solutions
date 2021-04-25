#include "TreeNode.h"
#include "utils.h"

class FindElements {
    unordered_set<int>S;
    void traverse(TreeNode*root,int cur){
        root->val=cur;
        S.insert(cur);
        if(root->left)traverse(root->left,cur*2+1);
        if(root->right)traverse(root->right,cur*2+2);
    }
public:
    FindElements(TreeNode* root) {
        traverse(root,0);
    }
    bool find(int target) {
        return S.count(target);
    }
};

int main()
{
    cout<<boolalpha;

    

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