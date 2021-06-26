#include "utils.h"

class Solution {
public:
    int balancedString(string s) {
        int toint[128];
        toint['Q']=0,toint['W']=1,toint['E']=2,toint['R']=3;
        int a[4]={0};
        for(char c:s)a[toint[c]]++;
        int part=s.size()/4;
        int ans=s.size();
        for(int i=0,j=0;i<s.size();){
            while(j<s.size()&&(a[0]>part||a[1]>part||a[2]>part||a[3]>part)){
                a[toint[s[j++]]]--;
            }
            if(a[0]>part||a[1]>part||a[2]>part||a[3]>part)break;
            chmin(ans,j-i);
            a[toint[s[i++]]]++;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="QWER";
    auto ans=sol.balancedString(s);
    DBG(ans);

    system("pause");
    return 0;
}
