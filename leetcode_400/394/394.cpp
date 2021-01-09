#include "utils.h"

class Solution {
    string fun(string&s,int&i){
        string res;
        int count=0;
        while(s[i]&&s[i]!=']'){
            if(isalpha(s[i]))res+=s[i++];
            else if(isdigit(s[i]))count=count*10+(s[i++]-'0');
            else{
                string temp=fun(s,++i);
                while(count){
                    count--;
                    res+=temp;
                }
                i++;
            }
        }
        return res;
    }
public:
    string decodeString(string s) {
        int i=0;
        return fun(s,i);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="3[a]2[bc]";
    auto ans=sol.decodeString(s);
    DBG(ans);

    system("pause");
    return 0;
}
