#include "TreeNode.h"
#include "utils.h"

char cc[4500][20]={0};//字符串池
pair<char*,TreeNode*>v[4500];//从叶结点往上，等长的状态池
int ccl=0,vl=0;//cc和v的长度

class Solution {
    unordered_map<TreeNode*,TreeNode*>P;//父结点映射
    int minval=25;
    void dfs1(TreeNode*root){//第一次dfs获取最小的叶结点值，避免从较大的叶结点出发
        if(!root->left&&!root->right)minval=min(minval,root->val);
        if(root->left)dfs1(root->left);
        if(root->right)dfs1(root->right);
    }
    bool dfs2(TreeNode*root){//返回值表示子孙有没有出发点
        if(!root->left&&!root->right){
            if(root->val==minval){//如果是叶结点且值最小，那就分配一个字符串，出发
                *cc[ccl]='a'+root->val;
                v[vl++]={cc[ccl++],root};
                return true;
            }
            else return false;
        }
        else{
            bool b1=root->left&&dfs2(root->left);
            bool b2=root->right&&dfs2(root->right);
            if(b1)P[root->left]=root;
            if(b2)P[root->right]=root;
            return b1||b2;
        }
    }
    void init(){
        memset(cc,0,ccl*20);
        ccl=vl=0;
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        init();
        dfs1(root);
        dfs2(root);
        int i=0;
        char curchar='a'+minval,nxtchar='z';
        for(;vl>1;i++){
            int k=0;
            for(int j=0;j<vl;j++){
                if(*v[j].first!=curchar)continue;
                v[k].first=v[j].first;
                v[k].second=P[v[j].second];
                if(!v[k].second){
                    return v[k].first-i;
                }
                *++v[k].first='a'+v[k].second->val;
                nxtchar=min(nxtchar,*v[k].first);
                k++;
            }
            vl=k;
            curchar=nxtchar;
            nxtchar='z';
        }
        for(;v[0].second=P[v[0].second];i++){
            *++v[0].first='a'+v[0].second->val;
        }
        return v[0].first-i;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[0,1,2,3,4,3,4]");
    DBGT(root);
    auto ans=sol.smallestFromLeaf(root);
    DBG(ans);

    system("pause");
    return 0;
}
