#include "utils.h"

class Solution {
    string s;
    vector<string>wordDict;
    vector<int>next[201];
    vector<string>ans;
    bool bs(string target){
        int low=0,high=wordDict.size();
        while(low<high){
            int mid=(low+high)/2;
            if(wordDict[mid]>=target)high=mid;
            else low=mid+1;
        }
        return low<wordDict.size()&&wordDict[low]==target;
    }
    void dfs(int cur,string path){
        if(cur==s.size()){
            ans.pb(path);
        }
        else{
            for(int i:next[cur]){
                if(path.size())dfs(i,path+" "+s.substr(cur,i-cur));
                else dfs(i,path+s.substr(cur,i-cur));
            }
        }
    }
public:
    vector<string> wordBreak(string _s, vector<string>&_wordDict) {
        s=_s;
        wordDict=_wordDict;
        sort(ALL(wordDict));
        REPR(i,s.size()-1){
            for(int j=1;j<=s.size()-i;j++){
                if((i+j==s.size()||next[i+j].size())&&bs(s.substr(i,j))){
                    next[i].pb(i+j);
                }
            }
        }
        dfs(0,"");
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="catsanddog";
    vector<string>wordDict{"cat", "cats", "and", "sand", "dog"};
    auto ans=sol.wordBreak(s,wordDict);
    DBGV(ans);

    system("pause");
    return 0;
}
