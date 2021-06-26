#include "utils.h"

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(a%1337==0)return 0;
        ll rest[b.size()];
        REP(i,b.size()){
            if(!i)rest[i]=a%1337;
            else{
                rest[i]=1;
                REP(j,10){
                    rest[i]=(rest[i]*rest[i-1])%1337;
                }
            }
        }
        int ans=1;
        REP(i,b.size()){
            REP(j,b[b.size()-1-i]){
                ans=(ans*rest[i])%1337;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int a=2147483647;
    vi b{2,0,0};
    auto ans=sol.superPow(a,b);
    DBG(ans);

    system("pause");
    return 0;
}
