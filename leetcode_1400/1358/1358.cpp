#include "utils.h"

class Solution {
    int cnt[3]={0},types=0;
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        for(int i=0,j=0;;i++){
            while(j<s.size()&&types<3){
                if(!cnt[s[j++]-'a']++)types++;
            }
            if(types<3)break;
            ans+=s.size()-j+1;
            if(!--cnt[s[i]-'a'])types--;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="abcabc";
    auto ans=sol.numberOfSubstrings(s);
    DBG(ans);

    system("pause");
    return 0;
}
