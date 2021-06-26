#include "utils.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>S;
        int num[128]={0};
        for(char c:s)num[c]++;
        bool inside[128];
        memset(inside,0,sizeof(inside));
        for(char c:s){
            if(!inside[c]){
                while(S.size()&&S.top()>=c&&num[S.top()]){
                    inside[S.top()]=false;
                    S.pop();
                }
                inside[c]=true;
                S.push(c);
            }
            num[c]--;
        }
        string ans;
        while(S.size()){
            ans+=S.top();
            S.pop();
        }
        reverse(ALL(ans));
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="cbacdcbc";
    auto ans=sol.removeDuplicateLetters(s);
    DBG(ans);

    system("pause");
    return 0;
}
