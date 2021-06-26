#include "utils.h"

class Solution {
public:
    bool isSelfCrossing(vector<int>& dis) {
        int a=0,b=0,x1=0,x2=0;
        REP(i,dis.size()){
            int d=dis[i];
            if(d>b){
                if(x1<0)return true;
                a=x1;
                x1=d-b;
                b=x2;
                x2=d;
            }
            else if(d<a){
                a=b=x2;
                x1=-1;
                x2=d;
            }
            else{
                if(x1<0)return true;
                a=b=x1;
                x1=-1;
                x2=d;
            }
        }
        return false;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vi dis{1,2,3,4};
    auto ans=sol.isSelfCrossing(dis);
    DBG(ans);

    system("pause");
    return 0;
}
