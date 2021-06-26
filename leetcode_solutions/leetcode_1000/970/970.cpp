#include "utils.h"

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vi xs{1},ys{1},ans;
        for(int val=x;val<bound&&x>1;val*=x)xs.pb(val);
        for(int val=y;val<bound&&y>1;val*=y)ys.pb(val);
        for(int a:xs){
            for(int b:ys){
                if(a+b<=bound)ans.pb(a+b);
            }
        }
        sort(ALL(ans));
        ans.resize(unique(ALL(ans))-ans.begin());
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int x=2;
    int y=3;
    int bound=10;
    auto ans=sol.powerfulIntegers(x,y,bound);
    DBGV(ans);

    system("pause");
    return 0;
}
