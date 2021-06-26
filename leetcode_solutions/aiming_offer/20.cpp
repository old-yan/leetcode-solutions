#include "utils.h"

class Solution {
    bool isinteger(string s){
        if(s[0]=='+'||s[0]=='-')s=s.substr(1);
        if(s.empty())return false;
        for(char c:s)
            if(!isdigit(c))return false;
        return true;
    }
    bool isfrac(string s){
        if(s[0]=='+'||s[0]=='-')s=s.substr(1);
        if(count(ALL(s),'.')!=1)return false;
        if(s.size()==1)return false;
        for(char c:s)
            if(!isdigit(c)&&c!='.')return false;
        return true;
    }
public:
    bool isNumber(string s) {
        while(s.size()&&s[0]==' ')s=s.substr(1);
        while(s.size()&&s.back()==' ')s.pop_back();
        int e=-1;
        REP(i,s.size())if(s[i]=='e'||s[i]=='E'){
            if(e>=0)return false;
            e=i;
        }
        if(e<0)return isinteger(s)||isfrac(s);
        else return (isinteger(s.substr(0,e))||isfrac(s.substr(0,e)))&&isinteger(s.substr(e+1));
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="    .1  ";
    auto ans=sol.isNumber(s);
    DBG(ans);

    system("pause");
    return 0;
}
