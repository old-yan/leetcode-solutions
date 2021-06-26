#include "utils.h"

class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        int a[32*length];
        memset(a,0,sizeof(a));
        fill(a+y*w+x1,a+y*w+x2+1,1);
        vi ans;
        for(int i=0;i<32*length;i+=32){
            ll k=0;
            for(int j=i;j<i+32;j++)
                k=k*2+a[j];
            ans.pb(k);
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int length=1;
    int w=32;
    int x1=30;
    int x2=31;
    int y=0;
    auto ans=sol.drawLine(length,w,x1,x2,y);
    DBGV(ans);

    system("pause");
    return 0;
}
