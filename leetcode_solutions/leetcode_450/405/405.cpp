#include "utils.h"

class Solution {
public:
    string toHex(int _num) {
        if(!_num)return "0";
        stack<char>S;
        ll num=_num;
        if(num<0)num+=4294967296;
        while(num){
            int a=num%16;
            num/=16;
            if(a<10)S.push('0'+a);
            else S.push('a'+a-10);
        }
        string ans;
        while(S.size()){
            ans+=S.top();
            S.pop();
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=26;
    auto ans=sol.toHex(num);
    DBG(ans);

    system("pause");
    return 0;
}
