#include "utils.h"

class Solution {
public:
    string reorganizeString(string S) {
        int num[128]={0};
        for(char c:S)num[c]++;
        sort(ALL(S),[&](char x,char y){return num[x]>num[y]||(num[x]==num[y]&&x<y);});
        string ans(S.size(),' ');
        if(S.size()%2){
            REP(i,S.size()){
                ans[(i*2)%(S.size()|1)]=S[i];
            }
        }
        else{
            REP(i,S.size()){
                ans[(i*2+1)%(S.size()|1)]=S[i];
            }
        }
        bool b=true;
        REP(i,S.size()-1)if(ans[i]==ans[i+1])b=false;
        if(b)return ans;
        else return "";
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string S="aab";
    auto ans=sol.reorganizeString(S);
    DBG(ans);

    system("pause");
    return 0;
}
