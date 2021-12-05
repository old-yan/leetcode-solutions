#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    //将链表摊到数组里，方便操作
    ListNode* deleteMiddle(ListNode* head) {
        //特判长度为一的情况
        if(!head->next)return nullptr;
        //将链表摊到数组 v 里
        vector<ListNode*>v;
        for(auto p=head;p;p=p->next)v.push_back(p);
        //删掉中间的结点
        v.erase(v.begin()+v.size()/2);
        //将剩余结点串起来
        for(int i=0;i+1<v.size();i++)v[i]->next=v[i+1];
        v.back()->next=nullptr;
        return v[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,3,4});
    auto ans=sol.deleteMiddle(head);
    DBG(ans);

    system("pause");
    return 0;
}