#include "Graph.h"
#include "utils.h"

class Solution {
    #define Node GraphNode//提交时注释本行
public:
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        vector<Node*>v(101,nullptr);
        queue<Node*>Q;
        v[1]=node;
        Q.push(node);
        while(Q.size()){
            auto a=Q.front();
            Q.pop();
            for(auto b:a->neighbors){
                if(!v[b->val]){
                    v[b->val]=b;
                    Q.push(b);
                }
            }
        }
        vector<Node*>copy(1,nullptr);
        FOR(i,1,v.size()){
            if(v[i])copy.pb(new Node(i));
            else break;
        }
        FOR(i,1,copy.size()){
            for(auto b:v[i]->neighbors){
                copy[i]->neighbors.pb(copy[b->val]);
            }
        }
        return copy[1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    Graph*g=new Graph(vvi{{2,4},{1,3},{2,4},{1,3}});
    DBG(g);
    auto ans=sol.cloneGraph(g->vertices[0]);
    DBG(ans);

    system("pause");
    return 0;
}
