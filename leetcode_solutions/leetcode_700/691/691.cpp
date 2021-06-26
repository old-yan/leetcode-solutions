#include "utils.h"

class Solution {
    int sticker_chars[50][26]={0};
    void countStickerChar(vector<string>&stickers){
        for(int i=0;i<stickers.size();i++){
            for(char c:stickers[i])sticker_chars[i][c-'a']++;
        }
    }
public:
    int minStickers(vector<string>&stickers, string target) {
        countStickerChar(stickers);
        int dp[1<<15];
        fill(dp,dp+(1<<15),10000000);
        dp[0]=0;
        for(int i=1;i<(1<<target.size());i++){
            for(int j=0;j<stickers.size();j++){
                int chars[26];
                memcpy(chars,sticker_chars[j],sizeof(chars));
                int icopy=i;
                for(int k=0;k<target.size();k++){
                    if((icopy&(1<<k))&&chars[target[k]-'a']){
                        chars[target[k]-'a']--;
                        icopy-=(1<<k);
                    }
                }
                dp[i]=min(dp[i],dp[icopy]+1);
            }
        }
        return dp[(1<<target.size())-1]==10000000?-1:dp[(1<<target.size())-1];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>stickers{"with", "example", "science"};
    string target="thehat";
    auto ans=sol.minStickers(stickers,target);
    DBG(ans);

    system("pause");
    return 0;
}
