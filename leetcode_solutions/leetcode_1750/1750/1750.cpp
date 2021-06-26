#include "utils.h"

class Solution {
public:
    int minimumLength(string s) {
        int left,right;
        for(left=0,right=s.size()-1;left<right;){
            char c1=s[left];
            char c2=s[right];
            if(c1!=c2)break;
            while(left<right&&s[left]==c1){
                left++;
            }
            while(left<right&&s[right]==c2){
                right--;
            }
        }
        if(right==left)return s[left]==s[left+1]||(left-1>=0&&s[left]==s[left-1])?0:1;
        else return right-left+1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="ca";
    auto ans=sol.minimumLength(s);
    DBG(ans);

    system("pause");
    return 0;
}
