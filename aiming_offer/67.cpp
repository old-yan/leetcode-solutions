#include "utils.h"

class Solution {
public:
    int strToInt(string str) {
        while(str[0]==' ')str=str.substr(1);
        ll signal=1,val=0;
        if(str[0]=='+'||str[0]=='-'){
            if(str[0]=='-')signal=-1;
            str=str.substr(1);
        }
        while(isdigit(str[0])){
            val=val*10+str[0]-'0';
            str=str.substr(1);
            if(abs(val)>INT_MAX){
                return signal==1?INT_MAX:INT_MIN;
            }
        }
        return signal*val;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string str="42";
    auto ans=sol.strToInt(str);
    DBG(ans);

    system("pause");
    return 0;
}
