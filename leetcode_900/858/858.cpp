#include "utils.h"

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int x=0,y=0,dir=1;
        while(true){
            if(dir>0){
                x=!x;
                y+=q;
                if(y>p){
                    y=p*2-y;
                    dir=-1;
                }
                else if(y==p)break;
            }
            else{
                x=!x;
                y-=q;
                if(y<0){
                    y=-y;
                    dir=1;
                }
                else if(y==0&&x)break;
            }
        }
        if(!x)return 2;
        else if(y)return 1;
        else return 0;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int p=2;
    int q=1;
    auto ans=sol.mirrorReflection(p,q);
    DBG(ans);

    system("pause");
    return 0;
}
