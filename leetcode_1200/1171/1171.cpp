#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        auto v=listtoarr(head);
        while(true){
            unordered_map<int,int>M{{0,0}};
            int cur=0;
            bool flag=false;
            REP(i,v.size()){
                cur+=v[i]->val;
                if(M.count(cur)){
                    v.erase(v.begin()+M[cur],v.begin()+i+1);
                    flag=true;
                    break;
                }
                else M[cur]=i+1;
            }
            if(!flag)break;
        }
        return arrtolist(v);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({1,2,-3,3,1});
    auto ans=sol.removeZeroSumSublists(head);
    DBG(ans);

    system("pause");
    return 0;
}
