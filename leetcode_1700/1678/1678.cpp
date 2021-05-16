#include "utils.h"

class Solution {
public:
    string interpret(string command) {
        string ans;
        for(int i=0;i<command.size();){
            if(command[i]=='G'){
                ans+="G";
                i++;
            }
            else if(command[i+1]==')'){
                ans+="o";
                i+=2;
            }
            else{
                ans+="al";
                i+=4;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string command="G()(al)";
    auto ans=sol.interpret(command);
    DBG(ans);

    system("pause");
    return 0;
}
