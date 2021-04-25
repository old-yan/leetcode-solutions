#include <functional>
#include "TreeNode.h"

//处理树上问题的助手（主要是LCA问题）
struct LCA{
    #define TREELEVEL 5
    unordered_map<TreeNode*,int>getid;
    vector<TreeNode*>seq;
    int parent[1<<TREELEVEL][TREELEVEL]={0},depth[1<<TREELEVEL]={0},lc[1<<TREELEVEL]={0},rc[1<<TREELEVEL]={0},num=0;
    LCA(TreeNode*root){
        cout<<"attention TREESIZE,<="<<(1<<TREELEVEL)<<'\n';
        if(!root)return;
        seq.push_back(nullptr);
        getid[nullptr]=0;
        [&](){
            int cursor=1;
            getid[root]=1;
            depth[1]=1;
            seq.push_back(root);
            for(;cursor<seq.size();cursor++){
                auto p=seq[cursor];
                if(p->left){
                    lc[cursor]=seq.size();
                    getid[p->left]=seq.size();
                    depth[seq.size()]=depth[cursor]+1;
                    seq.push_back(p->left);
                }
                if(p->right){
                    rc[cursor]=seq.size();
                    getid[p->right]=seq.size();
                    depth[seq.size()]=depth[cursor]+1;
                    seq.push_back(p->right);
                }
            }
            num=seq.size()-1;
        }();
        inline function<void(int,int)>traverse=[&](int cur,int par){
            parent[cur][0]=par;
            for(int i=1;i<TREELEVEL;i++)parent[cur][i]=parent[parent[cur][i-1]][i-1];
            if(lc[cur])traverse(lc[cur],cur);
            if(rc[cur])traverse(rc[cur],cur);
        };
        traverse(1,0);
    }
    int getDepth(){return *max_element(depth,depth+num+1);}
    int getDepth(TreeNode*cur){return depth[getid[cur]];}
    int getNum(){return num;}
    TreeNode*getParent(TreeNode*cur){
        return seq[parent[getid[cur]][0]];
    }
    TreeNode*getlca(TreeNode*x,TreeNode*y){
        int a=getid[x],b=getid[y];
        if(depth[a]>depth[b])swap(a,b);
        for(int d=depth[b]-depth[a],i=0;i<TREELEVEL;i++){
            if(d>>i&1)b=parent[b][i];
        }
        if(a==b)return seq[a];
        for(int i=TREELEVEL-1;i>=0;i--){
            if(parent[a][i]!=parent[b][i]){
                a=parent[a][i];
                b=parent[b][i];
            }
        }
        return seq[parent[a][0]];
    }
};