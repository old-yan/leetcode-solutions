#include "utils.h"

class Solution {
public:
    string maximumBinaryString(string binary) {
        int rightzero=0;
        for(char c:binary)rightzero+=c=='0';
        REP(i,binary.size()){
            if(binary[i]=='1')continue;
            if(!rightzero)binary[i]='1';
            else if(--rightzero){
                binary[i]='1';
                if(binary[i+1]=='1'){
                    binary[i+1]='0';
                }
            }
        }
        return binary;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string binary="000110";
    auto ans=sol.maximumBinaryString(binary);
    DBG(ans);

    system("pause");
    return 0;
}
