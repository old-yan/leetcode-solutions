#include "utils.h"

int dis_mat[26][26];
auto _initial=[](){
    REP(i,26){
        REP(j,26){
            dis_mat[i][j]=abs(i/6-j/6)+abs(i%6-j%6);
        }
    }
    return 0;
}();

class Solution {
    int dp[300][26];
public:
    int minimumDistance(string word) {
        memset(dp,0x3f,sizeof(dp));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>Q;
        REP(i,26){
            dp[0][i]=0;
            Q.emplace(0,0,i);
        }
        while(Q.size()){
            auto [dis,cur,i]=Q.top();
            Q.pop();
            if(dis!=dp[cur][i])continue;
            if(++cur==word.size())return dis;
            if((word[cur-1]==word[cur]&&chmin(dp[cur][i],dis))){
                Q.emplace(dis,cur,i);
            }
            if((i==word[cur]-'A'&&chmin(dp[cur][word[cur-1]-'A'],dis))){
                Q.emplace(dis,cur,word[cur-1]-'A');
            }
            if(chmin(dp[cur][i],dis+dis_mat[word[cur-1]-'A'][word[cur]-'A'])){
                Q.emplace(dp[cur][i],cur,i);
            }
            if(chmin(dp[cur][word[cur-1]-'A'],dis+dis_mat[i][word[cur]-'A'])){
                Q.emplace(dp[cur][word[cur-1]-'A'],cur,word[cur-1]-'A');
            }
        }
        return -1;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string word="UCAI";
    auto ans=sol.minimumDistance(word);
    DBG(ans);

    system("pause");
    return 0;
}
