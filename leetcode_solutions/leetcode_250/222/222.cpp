#include "utils.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        int h_left=0,h_right=0;
        for(auto p=root;p;p=p->left)h_left++;
        for(auto p=root;p;p=p->right)h_right++;
        if(h_left==h_right)return pow(2,h_left)-1;
        int low=1,high=pow(2,h_right)-1;
        while(low<high){
            int mid=(low+high)/2;
            int h=0;
            for(auto p=root;p;){
                h++;
                if(h==h_left)break;
                if(mid&(1<<(h_right-h)))p=p->right;
                else p=p->left;
            }
            if(h==h_right)high=mid;
            else low=mid+1;
        }
        return pow(2,h_right)-1+low;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    TreeNode*root=new TreeNode("[1,2,3,4,5,6]");
    auto ans=sol.countNodes(root);
    DBG(ans);

    system("pause");
    return 0;
}
