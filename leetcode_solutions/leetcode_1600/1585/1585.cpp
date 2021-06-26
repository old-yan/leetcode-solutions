#include "utils.h"

class Solution {
public:
    bool isTransformable(string s, string t) {
        queue<int>Q[10];
        REP(i,s.size())Q[s[i]-'0'].push(i);
        for(char c:t){
            if(Q[c-'0'].empty())return false;
            REP(i,c-'0'){
                if(Q[i].size()&&Q[i].front()<Q[c-'0'].front())return false;
            }
            Q[c-'0'].pop();
        }
        return true;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="84532";
    string t="34852";
    auto ans=sol.isTransformable(s,t);
    DBG(ans);

    system("pause");
    return 0;
}
