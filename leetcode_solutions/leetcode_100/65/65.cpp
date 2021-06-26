#include "utils.h"

class Solution {
    bool integer(string s){
        if(s.empty())return false;
        if(s[0]=='+'||s[0]=='-')s=s.substr(1,s.size()-1);
        if(s.empty())return false;
        REP(i,s.size()){
            if(!isdigit(s[i]))return false;
        }
        return true;
    }
    bool isfloat(string s){
        if(integer(s))return true;
        if(s.empty())return false;
        if(s[0]=='+'||s[0]=='-')s=s.substr(1,s.size()-1);
        if(s.size()<2)return false;
        bool dot=false;
        REP(i,s.size()){
            char c=s[i];
            if(!isdigit(c)){
                if(c=='.'){
                    if(dot)return false;
                    else dot=true;
                }
                else return false;
            }
        }
        return true;
    }
    bool e_number(string s){
        int e=-1;
        REP(i,s.size()){
            char c=s[i];
            if(!isdigit(c)){
                if(c=='e'){
                    if(e>=0)return false;
                    if(i==0||i==s.size()-1)return false;
                    e=i;
                }
            }
        }
        string s1=s.substr(0,e),s2=s.substr(e+1,s.size()-1-e);
        return isfloat(s1)&&integer(s2);
    }
public:
    bool isNumber(string s) {
        int i;
        for(i=0;i<s.size()&&s[i]==' ';i++);
        s=s.substr(i,s.size()-i);
        for(i=s.size()-1;i>=0&&s[i]==' ';i--);
        s=s.substr(0,i+1);
        return integer(s)||isfloat(s)||e_number(s);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="4e+";
    auto ans=sol.isNumber(s);
    DBG(ans);

    system("pause");
    return 0;
}
