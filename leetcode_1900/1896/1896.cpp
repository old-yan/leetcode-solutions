#include "utils.h"

class Solution {
    pair<int,int>parse(int&idx,string&expression){
        int c0=0,c1=0x3f3f3f3f,orc=0,andc=0x3f3f3f3f;
        while(true){
            int d0,d1;
            if(expression[idx]=='0'){
                d0=0,d1=1;
            }
            else if(expression[idx]=='1'){
                d0=1,d1=0;
            }
            else{
                ++idx;
                tie(d0,d1)=parse(idx,expression);
            }
            int tmp=c0;
            c0=min({c0+orc+d0,c0+andc+d0,c0+andc+d1,c1+andc+d0});
            c1=min({tmp+orc+d1,c1+orc+d0,c1+orc+d1,c1+andc+d1});
            if(!expression[++idx]||expression[idx]==')')break;
            if(expression[idx]=='&')andc=0,orc=1;
            else andc=1,orc=0;
            idx++;
        }
        return {c0,c1};
    }
public:
    int minOperationsToFlip(string expression) {
        int idx=0;
        auto [zero,one]=parse(idx,expression);
        return max(zero,one);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string expression="(0&0)&(0&0&0)";
    auto ans=sol.minOperationsToFlip(expression);
    DBG(ans);

    system("pause");
    return 0;
}
