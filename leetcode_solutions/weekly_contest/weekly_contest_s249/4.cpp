#include "TreeNode.h"
#include "utils.h"

class Solution {
    TreeNode*roots[50001]={0};
    TreeNode**replace[50001]={0};
    int size=0;
    bool same_leaf=false;
    //dfs每棵树，将根放入roots数组，将叶子的指针放到replace数组
    void dfs(TreeNode*&t,TreeNode*fa){
        if(!fa)roots[t->val]=t;
        size++;
        if(!t->left&&!t->right&&fa){
            if(replace[t->val])same_leaf=true;
            replace[t->val]=&t;
        }
        if(t->left)dfs(t->left,t);
        if(t->right)dfs(t->right,t);
    }
    //检查整棵树的合法性
    bool check(TreeNode*cur,int&pre){
        if(cur->left&&!check(cur->left,pre))return false;
        if(cur->val<=pre)return false;
        pre=cur->val,size--;
        if(cur->right&&!check(cur->right,pre))return false;
        return true;
    }
public:
    //本题为大模拟题，将所有的根和叶子关联起来，进行替换即可
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        for(auto&t:trees)dfs(t,nullptr);
        //叶子不能有重复，否则相应的根不知该和谁合并
        if(same_leaf)return nullptr;
        TreeNode* root=nullptr;
        //找到没有对应叶子的值，那就是根
        for(int val=1;val<=50000;val++)
            if(roots[val]&&!replace[val])
                if(!root)root=roots[val];
                else return nullptr;
        //将其他的根赋值给叶子指针对应的结点
        for(int val=1;val<=50000;val++){
            if(replace[val]&&roots[val]){
                size--;
                *replace[val]=roots[val];
            }
        }
        int pre=-1;
        //最后检查树的合法性，检查是否用上所有的结点
        if(root&&check(root,pre)&&!size)return root;
        else return nullptr;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<TreeNode*>trees{
        new TreeNode("[2,1,3]"),
        new TreeNode("[3,2]")
    };
    auto ans=sol.canMerge(trees);
    DBG(ans);

    system("pause");
    return 0;
}
