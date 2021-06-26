#include "utils.h"

class Solution {
public:
    string freqAlphabets(string s) {
        int n=s.size();
        string ans;
        for(int i=0;i<n;){
            if(i+2<n&&s[i+2]=='#'){
                ans+=char('a'+s2i(s.substr(i,2))-1);
                i+=3;
            }
            else{
                ans+=char('a'+(s[i]-'1'));
                i++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="10#11#12";
    auto ans=sol.freqAlphabets(s);
    DBG(ans);

    system("pause");
    return 0;
}
