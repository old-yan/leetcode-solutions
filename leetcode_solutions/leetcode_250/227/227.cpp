#include "utils.h"

class Solution {
    int readint(string&s,int&idx){
        int val=0;
        while(isdigit(s[idx])){
            val=val*10+(s[idx++]-'0');
        }
        return val;
    }
    int fun(string&s,int&idx){
        int val=readint(s,idx);
        while(s[idx]=='*'||s[idx]=='/'){
            int signal=s[idx]=='*'?1:2;
            idx++;
            int val2=readint(s,idx);
            if(signal==1)val*=val2;
            else val/=val2;
        }
        return val;
    }
public:
    int calculate(string s) {
        string ss;
        for(char c:s)if(c!=' ')ss+=c;
        int idx=0;
        int ans=0;
        while(idx<ss.size()){
            int signal=1;
            if(ss[idx]=='+')idx++;
            else if(ss[idx]=='-'){
                signal=-1;
                idx++;
            }
            ans+=signal*fun(ss,idx);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="3+5/2";
    auto ans=sol.calculate(s);
    DBG(ans);

    system("pause");
    return 0;
}
