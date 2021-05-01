#include "utils.h"

int steps[300001]={0};
auto _initial=[](){
    memset(steps,0xff,sizeof(steps));
    steps[1]=0;
    function<int(int)>getstep;
    getstep=[&](int x){
        if(steps[x]>=0)return steps[x];
        else return steps[x]=getstep(x%2?x*3+1:x/2)+1;
    };
    FOR(i,1,1001){
        getstep(i);
    }
    return 0;
}();

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vi v(hi-lo+1);
        iota(ALL(v),lo);
        nth_element(v.begin(),v.begin()+k-1,v.end(),[](int x,int y){
            if(steps[x]!=steps[y])return steps[x]<steps[y];
            else return x<=y;
        });
        return v[k-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int lo=12;
    int hi=15;
    int k=2;
    auto ans=sol.getKth(lo,hi,k);
    DBG(ans);

    system("pause");
    return 0;
}
