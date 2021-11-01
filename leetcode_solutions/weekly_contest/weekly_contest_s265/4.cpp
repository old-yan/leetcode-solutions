#include "utils.h"

class Solution {
    string s1,s2;
    unordered_map<int,bool>dp[41][41];
    //dfs(i,j,k)表示：
    //  如果 k 为正，那么 s1.substr(i) 能否匹配 【任意字符】*abs(k)+s2.substr(j) 
    //  如果 k 为负，那么 【任意字符】*abs(k)+s1.substr(i) 能否匹配 s2.substr(j)
    //  如果 k 为零，那么 s1.substr(i) 能否匹配 s2.substr(j) 
    //搜索的时候加个记忆化，就可以过了
    bool dfs(int i,int j,int k){
        //先搜缓存，缓存里有答案直接返回答案
        if(dp[i][j].count(k))return dp[i][j][k];
        //如果两个下标都到了末尾，那么必须 k==0 才能匹配
        if(i==s1.size() and j==s2.size()){
            return dp[i][j][k]=(k==0);
        }
        //如果 k 为正数，对应第一种情况，那我们让 i 增长，去消耗右边的【任意字符】
        if(k>0){
            if(isalpha(s1[i]) and dfs(i+1,j,k-1))return dp[i][j][k]=true;
            if(isdigit(s1[i]) and dfs(i+1,j,k-(s1[i]-'0')))return dp[i][j][k]=true;
            if(isdigit(s1[i]) and isdigit(s1[i+1]) and dfs(i+2,j,k-(s1[i]-'0')*10-(s1[i+1]-'0')))return dp[i][j][k]=true;
            if(isdigit(s1[i]) and isdigit(s1[i+1]) and isdigit(s1[i+2]) and dfs(i+3,j,k-(s1[i]-'0')*100-(s1[i+1]-'0')*10-(s1[i+2]-'0')))return dp[i][j][k]=true;
            return dp[i][j][k]=false;
        }
        //如果 k 为负数，对应第二种情况，那我们让 j 增长，去消耗左边的【任意字符】
        else if(k<0){
            if(isalpha(s2[j]) and dfs(i,j+1,k+1))return dp[i][j][k]=true;
            if(isdigit(s2[j]) and dfs(i,j+1,k+(s2[j]-'0')))return dp[i][j][k]=true;
            if(isdigit(s2[j]) and isdigit(s2[j+1]) and dfs(i,j+2,k+(s2[j]-'0')*10+(s2[j+1]-'0')))return dp[i][j][k]=true;
            if(isdigit(s2[j]) and isdigit(s2[j+1]) and isdigit(s2[j+2]) and dfs(i,j+3,k+(s2[j]-'0')*100+(s2[j+1]-'0')*10+(s2[j+2]-'0')))return dp[i][j][k]=true;
            return dp[i][j][k]=false;
        }
        //如果 k==0,既可以让 i 增长，也可以让 j 增长，但是如果 s1[i] 和 s2[j] 同为字母，它俩必须一样
        else{
            if(isalpha(s1[i]) and isalpha(s2[j]) and s1[i]==s2[j] and dfs(i+1,j+1,0))return dp[i][j][k]=true;
            if(isdigit(s1[i]) and dfs(i+1,j,k-(s1[i]-'0')))return dp[i][j][k]=true;
            if(isdigit(s1[i]) and isdigit(s1[i+1]) and dfs(i+2,j,k-(s1[i]-'0')*10-(s1[i+1]-'0')))return dp[i][j][k]=true;
            if(isdigit(s1[i]) and isdigit(s1[i+1]) and isdigit(s1[i+2]) and dfs(i+3,j,k-(s1[i]-'0')*100-(s1[i+1]-'0')*10-(s1[i+2]-'0')))return dp[i][j][k]=true;
            if(isdigit(s2[j]) and dfs(i,j+1,k+(s2[j]-'0')))return dp[i][j][k]=true;
            if(isdigit(s2[j]) and isdigit(s2[j+1]) and dfs(i,j+2,k+(s2[j]-'0')*10+(s2[j+1]-'0')))return dp[i][j][k]=true;
            if(isdigit(s2[j]) and isdigit(s2[j+1]) and isdigit(s2[j+2]) and dfs(i,j+3,k+(s2[j]-'0')*100+(s2[j+1]-'0')*10+(s2[j+2]-'0')))return dp[i][j][k]=true;
            return dp[i][j][k]=false;
        }
    }
public:
    //本题一看就可以用搜索来解决问题。
    //经过分析，本题的状态路径存在重复计算，那么我们就要加个记忆化
    bool possiblyEquals(string s1, string s2) {
        this->s1=s1;
        this->s2=s2;
        return dfs(0,0,0);
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s1="112s";
    string s2="g841";
    auto ans=sol.possiblyEquals(s1,s2);
    DBG(ans);

    system("pause");
    return 0;
}