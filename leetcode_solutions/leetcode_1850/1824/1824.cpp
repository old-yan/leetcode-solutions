#include "utils.h"

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size()+5;
        int a=n,b=0,c=n;
        for(int o:obstacles){
            if(o){
                if(o==1){
                    a=n;
                }
                else if(o==2){
                    b=n;
                }
                else{
                    c=n;
                }
                int d=min({a,b,c});
                if(o==1){
                    chmin(b,d+1);
                    chmin(c,d+1);
                }
                else if(o==2){
                    chmin(a,d+1);
                    chmin(c,d+1);
                }
                else{
                    chmin(a,d+1);
                    chmin(b,d+1);
                }
            }
            else{
                int d=min({a,b,c});
                chmin(a,d+1);
                chmin(b,d+1);
                chmin(c,d+1);
            }
        }
        return min({a,b,c});
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi obstacles{0,1,2,3,0};
    auto ans=sol.minSideJumps(obstacles);
    DBG(ans);

    system("pause");
    return 0;
}
