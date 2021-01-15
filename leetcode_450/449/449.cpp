#include "utils.h"

class Codec {
public:
    void dfs1(TreeNode*p,char c[],int&idx){
        c[idx++]='(';
        if(p){
            string temp=i2s(p->val);
            strcpy(c+idx,&temp[0]);
            idx+=temp.size();
            dfs1(p->left,c,idx);
            dfs1(p->right,c,idx);
        }
        c[idx++]=')';
    };
    string serialize(TreeNode* root) {
        char c[200000]={0};
        int idx=0;
        dfs1(root,c,idx);
        return c;
    }

    TreeNode* dfs2(string&data,int&idx){
        if(data[++idx]==')'){
            idx++;
            return nullptr;
        }
        string temp;
        while(data[idx]!='(')temp+=data[idx++];
        TreeNode*p=new TreeNode(s2i(temp));
        p->left=dfs2(data,idx);
        p->right=dfs2(data,idx);
        ++idx;
        return p;
    }
    TreeNode* deserialize(string data) {
        int idx=0;
        return dfs2(data,idx);
    }
};

int main()
{
    cout<<boolalpha;

    TreeNode*root=new TreeNode("1,2,3,4,5,null,7");
    DBGT(root);
    Codec*obj=new Codec();
    string s=obj->serialize(root);
    DBG(s);
    auto ans=obj->deserialize(s);
    DBGT(ans);

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