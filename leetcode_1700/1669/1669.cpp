#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        auto v1=listtoarr(list1);
        auto v2=listtoarr(list2);
        v1.erase(v1.begin()+a,v1.begin()+b+1);
        v1.insert(v1.begin()+a,ALL(v2));
        return arrtolist(v1);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*list1=makelistnode({0,1,2,3,4,5});
    int a=3;
    int b=4;
    ListNode*list2=makelistnode({1000000,1000001,1000002});
    auto ans=sol.mergeInBetween(list1,a,b,list2);
    DBG(ans);

    system("pause");
    return 0;
}
