#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        auto v=listtoarr(head);
        vector<bool>appear(v.size(),false);
        for(int a:G)appear[a]=true;
        int keep=0,cnt=0;
        for(auto p:v){
            if(appear[p->val]){
                if(!keep++)cnt++;
            }
            else{
                keep=0;
            }
        }
        return cnt;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode*head=makelistnode({0,1,2,3});
    vi G{0,1,3};
    auto ans=sol.numComponents(head,G);
    DBG(ans);

    system("pause");
    return 0;
}
