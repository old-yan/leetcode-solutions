#include "utils.h"

class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty())return 0;
        int ans=k;
        int num[26]={0};
        int maxSame=0;
        for(int i=0,j=-1;j<int(s.size());i++){
            while(j<int(s.size())&&maxSame+k>=j-i+1){
                ++j;
                if(j==s.size())break;
                num[s[j]-'A']++;
                chmax(maxSame,num[s[j]-'A']);
                if(maxSame+k<j-i+1)break;
            }
            chmax(ans,j-i);
            num[s[i]-'A']--;
        }
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="AABABBA";
    int k=1;
    auto ans=sol.characterReplacement(s,k);
    DBG(ans);

    system("pause");
    return 0;
}
