#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    //链表不能按下标访问，很不方便，所以把链表放到数组里处理
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>v;
        for(auto p=head;p;p=p->next)v.push_back(p->val);
        //criticals 存放极值点下标
        vector<int>criticals;
        for(int i=1;i+1<v.size();i++){
            if(v[i]>v[i-1] and v[i]>v[i+1])criticals.push_back(i);
            else if(v[i]<v[i-1] and v[i]<v[i+1])criticals.push_back(i);
            else continue;
        }
        if(criticals.size()<=1)return {-1,-1};
        int mindis=INT_MAX;
        for(int i=1;i<criticals.size();i++){
            mindis=min(mindis,criticals[i]-criticals[i-1]);
        }
        //maxdis用最后的减最前的即可得到
        return {mindis,criticals.back()-criticals.front()};
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode *head=makelistnode({5,3,1,2,5,1,2});
    auto ans=sol.nodesBetweenCriticalPoints(head);
    DBGV(ans);

    system("pause");
    return 0;
}