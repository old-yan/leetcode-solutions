#include "utils.h"

class Solution {
public:
    int minimumOperations(string leaves) {
        int o=0,r=0x3f3f3f3f,ry=0x3f3f3f3f,ryr=0x3f3f3f3f;
        for(char c:leaves){
            if(c=='r'){
                ryr=min(ryr,ry);
                ry=min(ry+1,r+1);
                r=min(r,o);
            }
            else{
                ryr=min(ryr+1,ry+1);
                ry=min(ry,r);
                r=min(r+1,o+1);
            }
            o=0x3f3f3f3f;
        }
        return ryr;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string leaves="rrryyyrryyyrr";
    auto ans=sol.minimumOperations(leaves);
    DBG(ans);

    system("pause");
    return 0;
}
