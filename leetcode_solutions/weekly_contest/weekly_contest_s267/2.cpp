#include "ListNode.h"
#include "utils.h"

class Solution {
public:
    //对于反转问题，链表不如数组操作方便，所以先把链表摊到数组里
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<ListNode*>arr;
        for(auto p=head;p;p=p->next)arr.push_back(p);
        //找出每一个区间
        for(int i=0,len=1;i<arr.size();){
            //如果末端还在界内，那么区间长为len，然后考虑下一个区间
            if(i+len<arr.size()){
                if(len%2==0)
                    reverse(arr.begin()+i,arr.begin()+i+len);
                i+=len++;
            }
            //如果末端不在界内，那么区间长为arr.size()-i，然后无需考虑下一个区间
            else{
                if((arr.size()-i)%2==0)
                    reverse(arr.begin()+i,arr.end());
                break;
            }
        }
        //把所有结点串起来
        for(int i=0;i<arr.size();i++){
            if(i+1<arr.size())arr[i]->next=arr[i+1];
            else arr[i]->next=nullptr;
        }
        return arr[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    ListNode *head=makelistnode({5,2,6,3,9,1,7,3,8,4});
    auto ans=sol.reverseEvenLengthGroups(head);
    DBG(ans);

    system("pause");
    return 0;
}