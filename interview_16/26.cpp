#include "utils.h"

class Solution {
    int parse(int&idx,string&s){
        int signal=1,val=0;
        if(s[idx]=='-'){
            signal=-1;
            idx++;
        }
        while(isdigit(s[idx]))val=val*10+(s[idx++]-'0');
        val*=signal;
        while(s[idx]&&(s[idx]=='*'||s[idx]=='/')){
            char c=s[idx++];
            int num=0;
            while(isdigit(s[idx]))num=num*10+(s[idx++]-'0');
            if(c=='*')val*=num;
            else val/=num;
        }
        return val;
    }
public:
    int calculate(string _s) {
        int idx=0,ans=0,signal=1;
        string s;
        for(char c:_s)if(c!=' ')s+=c;
        while(true){
            auto res=parse(idx,s);
            ans+=res*signal;
            if(s[idx]){
                signal=s[idx++]=='+'?1:-1;
            }
            else break;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="3+2*2";
    auto ans=sol.calculate(s);
    DBG(ans);

    system("pause");
    return 0;
}
