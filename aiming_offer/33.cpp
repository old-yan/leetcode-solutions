#include "utils.h"

class Solution {
    bool check(int h,int t,int floor,int ceil,vi&postorder){
        if(h>t)return true;
        FOR(i,h,t+1){
            if(postorder[i]>=ceil||postorder[i]<=floor)return false;
        }
        int root=postorder[t];
        int cursor=0;
        for(cursor=h;postorder[cursor]<root;cursor++);
        return check(h,cursor-1,floor,root,postorder)&&check(cursor,t-1,root,ceil,postorder);
        
    }
public:
    bool verifyPostorder(vector<int>& postorder) {
        return check(0,postorder.size()-1,INT_MIN,INT_MAX,postorder);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi postorder{1,6,3,2,5};
    auto ans=sol.verifyPostorder(postorder);
    DBG(ans);

    system("pause");
    return 0;
}
