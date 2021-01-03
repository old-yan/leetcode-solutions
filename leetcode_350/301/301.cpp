#include "utils.h"

class Solution {
    string s;
    vi nextL;
    vi nextR;
    vi nextChar;
    vi afterPaired;
    vi afterRestRight;
    char c[50];
    vector<string>ans;
    int num_of_bracket=0;
    void dfs(int i,int idx,int restLeft,int paired){
        if(i==s.size()){
            c[idx]=0;
            if(num_of_bracket==paired){
                ans.pb(c);
            }
        }
        else{
            c[idx++]=s[i];
            if(s[i]=='('){
                restLeft++;
            }
            else if(s[i]==')'){
                restLeft--;
                paired++;
            }
            int j=nextL[i];
            if(j<nextChar[i]&&paired+min(restLeft,afterRestRight[j])+afterPaired[j]==num_of_bracket){
                dfs(j,idx,restLeft,paired);
            }
            j=nextR[i];
            if(j<nextChar[i]&&restLeft&&paired+min(restLeft,afterRestRight[j])+afterPaired[j]==num_of_bracket){
                dfs(j,idx,restLeft,paired);
            }
            j=nextChar[i];
            if((j==s.size()&&!restLeft)||(j<s.size()&&paired+min(restLeft,afterRestRight[j])+afterPaired[j]==num_of_bracket)){
                dfs(j,idx,restLeft,paired);
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string _s) {
        s=_s;
        nextL.resize(s.size());
        nextR.resize(s.size());
        nextChar.resize(s.size());
        afterRestRight.resize(s.size());
        afterPaired.resize(s.size());
        int firstL=s.size(),firstR=s.size(),firstChar=s.size(),restRight=0,paired=0;
        REPR(i,s.size()-1){
            nextL[i]=firstL;
            nextR[i]=firstR;
            nextChar[i]=firstChar;
            if(s[i]==')'){
                firstR=i;
                restRight++;
            }
            else{
                if(s[i]=='('){
                    firstL=i;
                    if(restRight){
                        restRight--;
                        paired++;
                    }
                }
                else{
                    firstChar=i;
                }
            }
            afterRestRight[i]=restRight;
            afterPaired[i]=paired;
        }
        num_of_bracket=afterPaired[0];
        dfs(firstChar,0,0,0);
        if(firstL<firstChar)dfs(firstL,0,0,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="(()";
    auto ans=sol.removeInvalidParentheses(s);
    DBGV(ans);

    system("pause");
    return 0;
}
