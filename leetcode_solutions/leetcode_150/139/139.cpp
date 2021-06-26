#include "utils.h"

class Solution {
    vector<string>wordDict;
    bool bs(string target){
        int low=0,high=wordDict.size();
        while(low<high){
            int mid=(low+high)/2;
            if(wordDict[mid]>=target)high=mid;
            else low=mid+1;
        }
        return low<wordDict.size()&&wordDict[low]==target;
    }
public:
    bool wordBreak(string s, vector<string>&_wordDict) {
        int dp[s.size()+1];
        memset(dp,0,sizeof(dp));
        dp[s.size()]=1;
        wordDict=_wordDict;
        sort(ALL(wordDict));
        REPR(i,s.size()-1){
            for(int j=1;j<=s.size()-i;j++){
                if(dp[i+j]&&bs(s.substr(i,j))){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[0];
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="applepenapple";
    vector<string>wordDict{"apple", "pen"};
    auto ans=sol.wordBreak(s,wordDict);
    DBG(ans);

    system("pause");
    return 0;
}
