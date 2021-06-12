#include "TreeNode.h"
#include "utils.h"

class Codec {
public:
    string serialize(TreeNode* root) {
        if(!root)return "()";
        else return "("+i2s(root->val)+serialize(root->left)+serialize(root->right)+")";
    }
    TreeNode*fun(string&data,int&idx){
        if(data[++idx]==')'){
            idx++;
            return nullptr;
        }
        int signal=1;
        if(data[idx]=='-'){
            idx++;
            signal=-1;
        }
        int val=0;
        while(isdigit(data[idx])){
            val=val*10+data[idx++]-'0';
        }
        TreeNode*p=new TreeNode(val*signal,fun(data,idx),fun(data,idx));
        idx++;
        return p;
    }
    TreeNode* deserialize(string data) {
        int idx=0;
        return fun(data,idx);
    }
};

int main()
{
    cout<<boolalpha;

    TreeNode*root=new TreeNode("[1,2,3,null,null,4,5]");
    DBG(root);
    Codec encoder;
    Codec decoder;
    string s=encoder.serialize(root);
    DBG(s);
    auto ans=decoder.deserialize(s);
    DBG(ans);

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