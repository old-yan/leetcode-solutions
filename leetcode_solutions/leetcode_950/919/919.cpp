#include "TreeNode.h"
#include "utils.h"

class CBTInserter {
    vector<TreeNode*>nodes;
public:
    CBTInserter(TreeNode* root) {
        nodes.pb(root);
        REP(i,nodes.size()){
            if(nodes[i]->left)nodes.pb(nodes[i]->left);
            if(nodes[i]->right)nodes.pb(nodes[i]->right);
        }
    }
    int insert(int v) {
        if(nodes.size()%2){
            auto parent=nodes[nodes.size()/2];
            parent->left=new TreeNode(v);
            nodes.pb(parent->left);
            return parent->val;
        }
        else{
            auto parent=nodes[(nodes.size()-1)/2];
            parent->right=new TreeNode(v);
            nodes.pb(parent->right);
            return parent->val;
        }
    }
    TreeNode* get_root() {
        return nodes[0];
    }
};

int main()
{
    cout<<boolalpha;

	CBTInserter*obj=new CBTInserter(new TreeNode("[1,2,3,4,5,6]"));
	obj->insert(7);
    obj->insert(8);
	obj->get_root();

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