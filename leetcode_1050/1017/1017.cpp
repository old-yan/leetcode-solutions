#include "utils.h"

class Solution {
public:
    string baseNeg2(int N) {
        if(N==0)return "0";
        vi v(100,0);
        int i=0,j=1;
        while(N){
            if(N/j%2){
                v[i]=1;
                if(i%2)N+=j;
                else N-=j;
            }
            i++;
            j<<=1;
        }
        string ans;
        while(--i>=0)ans+='0'+v[i];
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    int N=5;
    auto ans=sol.baseNeg2(N);
    DBG(ans);

    system("pause");
    return 0;
}
