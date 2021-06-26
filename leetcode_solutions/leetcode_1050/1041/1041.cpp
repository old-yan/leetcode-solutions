#include "utils.h"

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0,k=0;
        while(true){
            for(char c:instructions){
                if(c=='G'){
                    x+=di[k];
                    y+=dj[k];
                }
                else if(c=='L')k=(k+1)%4;
                else k=(k+3)%4;
            }
            if(!k)break;
        }
        return !x&&!y;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string instructions="GGLLGG";
    auto ans=sol.isRobotBounded(instructions);
    DBG(ans);

    system("pause");
    return 0;
}
