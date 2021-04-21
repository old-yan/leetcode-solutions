#include "utils.h"

class Solution {
    vector<string>words;
    vi score;
    int cnt[26]={0},ans=0;
    void dfs(int idx,int curscore){
        if(idx==words.size()){
            chmax(ans,curscore);
        }
        else{
            bool flag=true;
            for(char c:words[idx]){
                curscore+=score[c-'a'];
                if(!cnt[c-'a']--)flag=false;
            }
            if(flag)dfs(idx+1,curscore);
            for(char c:words[idx]){
                curscore-=score[c-'a'];
                ++cnt[c-'a'];
            }
            dfs(idx+1,curscore);
        }
    }
public:
    int maxScoreWords(vector<string>& _words, vector<char>& letters, vector<int>& _score) {
        words=_words;
        score=_score;
        for(char c:letters)cnt[c-'a']++;
        dfs(0,0);
        return ans;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    vector<string>words{
        "dog","cat","dad","good"
    };
    vector<char>letters{
        'a','a','c','d','d','d','g','o','o'
    };
    vi score{1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    auto ans=sol.maxScoreWords(words,letters,score);
    DBG(ans);

    system("pause");
    return 0;
}
