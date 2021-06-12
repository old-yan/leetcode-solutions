#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)return nullptr;
        auto v1=listtoarr(headA);
        auto v2=listtoarr(headB);
        if(v1.back()!=v2.back())return nullptr;
        for(int i=v1.size()-1,j=v2.size()-1;i>=0&&j>=0;i--,j--){
            if(v1[i]!=v2[j])return v1[i+1];
        }
        if(v1.size()<v2.size())return v1.front();
        else return v2.front();
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    auto v=listtoarr(makelistnode({8,4,5}));
    auto v1=listtoarr(makelistnode({4,1}));
    auto v2=listtoarr(makelistnode({5,0,1}));
    v1.insert(v1.end(),v.begin(),v.end());
    ListNode*headA=arrtolist(v1);
    v2.insert(v2.end(),v.begin(),v.end());
    ListNode*headB=arrtolist(v2);
    DBG(headA);
    DBG(headB);
    auto ans=sol.getIntersectionNode(headA,headB);
    DBG(ans);

    system("pause");
    return 0;
}
