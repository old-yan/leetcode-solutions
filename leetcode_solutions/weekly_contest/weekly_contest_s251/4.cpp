#include "utils.h"

class Solution {
    struct node{
        string content;
        node*parent;
        map<string,node*>sons;
        int son_num=0;
        vector<int>feature;
        int hash_id;
        node(node*_parent,const string&_content=""):parent(_parent),content(_content){}
        node* new_son(const string&s){
            if(sons.count(s))return sons[s];
            else{
                son_num++;
                return sons[s]=new node(this,s);
            }
        }
    };
    queue<node*>Q;
    //给每一个string一个独特的数字id
    unordered_map<string,int>stringid;
    //给每一个子树序列一个独特的数字id
    map<vector<int>,int>hash_id;
    //对每个子树的哈希出现次数进行统计
    map<int,int>hash_count;
    //找出所有叶子
    void find_leaf(node*cur){
        if(cur->sons.empty())Q.push(cur);
        else for(auto&&[_,son]:cur->sons)find_leaf(son);
    }
    //遍历生成答案
    void dfs(node*cur,vector<vector<string>>&ans,vector<string>&path){
        if(cur->sons.empty()||hash_count[cur->hash_id]==1){
            if(path.size())ans.push_back(path);
            for(auto&&[_,son]:cur->sons){
                path.push_back(son->content);
                dfs(son,ans,path);
                path.pop_back();
            }
        }
    }
public:
    //本题可以参考力扣 652 树的哈希
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        node*root=new node(nullptr);
        //建树
        for(auto&p:paths){
            node*cur=root;
            for(auto&s:p){
                if(!stringid.count(s))stringid[s]=stringid.size();
                cur=cur->new_son(s);
            }
        }
        //找出叶子
        find_leaf(root);
        //从叶到根进行拓扑遍历，每当遍历到一个结点时保证其子树已被遍历
        //通过所有子树的哈希值，铺成一排就可以当成该结点为根的树的特征值
        while(Q.size()){
            auto p=Q.front();
            Q.pop();
            for(auto&&[_,son]:p->sons){
                p->feature.push_back(son->hash_id);
                p->feature.push_back(stringid[son->content]);
            }
            if(hash_id.count(p->feature))p->hash_id=hash_id[p->feature];
            else p->hash_id=hash_id[p->feature]=hash_id.size();
            hash_count[p->hash_id]++;
            if(p->parent){
                p->parent->son_num--;
                if(!p->parent->son_num)Q.push(p->parent);
            }
        }
        //dfs获取答案
        vector<vector<string>>ans;
        vector<string>path;
        dfs(root,ans,path);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<vector<string>>paths{
        {"a"},
        {"c"},
        {"d"},
        {"a","b"},
        {"c","b"},
        {"d","a"}
    };
    auto ans=sol.deleteDuplicateFolder(paths);
    DBGVV(ans);

    system("pause");
    return 0;
}
