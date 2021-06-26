#include "utils.h"

class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        ll w=min({xPos,num-xPos-1,yPos,num-yPos-1});
        ll a=num-w*2;
        ll cnt=((ll)(num-1)*4+(a+1)*4)*w/2;
        int r1=w,r2=num-1-w,c1=w,c2=num-1-w;
        if(xPos==r1)cnt+=yPos-c1+1;
        else{
            cnt+=a-1;
            if(yPos==c2)cnt+=xPos-r1+1;
            else{
                cnt+=a-1;
                if(xPos==r2)cnt+=c2-yPos+1;
                else{
                    cnt+=a-1;
                    cnt+=r2-xPos+1;
                }
            }
        }
        return (cnt+8)%9+1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int num=4;
    int xPos=1;
    int yPos=2;
    auto ans=sol.orchestraLayout(num,xPos,yPos);
    DBG(ans);

    system("pause");
    return 0;
}
