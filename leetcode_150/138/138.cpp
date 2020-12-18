#include "utils.h"

class Solution {
    #define Node RandomNode//提交时注释本行
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        unordered_map<Node*,int>M;
        vector<Node*>old;
        for(auto p=head;p;p=p->next){
            M[p]=M.size();
            old.pb(p);
        }
        vector<Node*>v;
        REP(i,M.size())v.pb(new Node(old[i]->val));
        REP(i,v.size()){
            if(i+1<v.size())v[i]->next=v[i+1];
        }
        REP(i,v.size()){
            if(old[i]->random)v[i]->random=v[M[old[i]->random]];
        }
        return v[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    RandomNode*head=makerandomnode("[7,null],[13,0],[11,4],[10,2],[1,0]");
    DBGN(head);
    auto ans=sol.copyRandomList(head);
    DBGN(ans);

    system("pause");
    return 0;
}
