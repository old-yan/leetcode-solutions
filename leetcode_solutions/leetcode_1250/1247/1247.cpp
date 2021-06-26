#include "utils.h"

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n=s1.size();
        int a=0,b=0;
        REP(i,n){
            if(s1[i]=='x'&&s2[i]=='y')a++;
            else if(s1[i]=='y'&&s2[i]=='x')b++;
        }
        if((a+b)%2)return -1;
        else return a/2+b/2+a%2*2;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="xy";
    string s2="yx";
    auto ans=sol.minimumSwap(s1,s2);
    DBG(ans);

    system("pause");
    return 0;
}
