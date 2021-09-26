#include "utils.h"

class Solution {
    int n;
    string s;
    bool vis[31][31]={0};
    vector<int>dp[31][31];
    //用暴力法求出正确答案
    int right_ans(){
        vector<int>v;
        //把所有数字/符号都放到数组里，数字就存数字，乘号存-1，加号存-2
        for(char c:s){
            if(c=='*')v.push_back(-1);
            else if(c=='+')v.push_back(-2);
            else v.push_back(c-'0');
        }
        //先搜索乘号，搜到之后把前后数字相乘，三项变一项
        while(true){
            auto _find=find(ALL(v),-1);
            if(_find==v.end())break;
            ll a=*prev(_find),b=*next(_find);
            *prev(_find)=a*b;
            _find=v.erase(_find);
            _find=v.erase(_find);
        }
        //再搜索加号，搜到之后把前后数字相加，三项变一项
        while(true){
            auto _find=find(ALL(v),-2);
            if(_find==v.end())break;
            ll a=*prev(_find),b=*next(_find);
            *prev(_find)=a+b;
            _find=v.erase(_find);
            _find=v.erase(_find);
        }
        //得到正确答案
        return v[0];
    }
    //dfs寻找每个区间的可能的数值，要加记忆化
    vector<int>& dfs(int l,int r){
        if(vis[l][r])return dp[l][r];
        vis[l][r]=true;
        //l==r说明区间长度为1
        if(l==r){
            dp[l][r].push_back(s[l]-'0');
            return dp[l][r];
        }
        //枚举区间内的所有符号，令其作为最后的运算符
        vector<int>v;
        for(int i=l+1;i<r;i+=2){
            for(auto a:dfs(l,i-1))
                for(auto b:dfs(i+1,r)){
                    int res=s[i]=='*'?a*b:a+b;
                    if(res<=1000)v.push_back(res);
                }
        }
        //注意去个重，可以加速很多
        static bitset<1001>B;B.reset();
        for(int a:v)if(!B[a]){
            B.set(a);dp[l][r].push_back(a);
        }
        return dp[l][r];
    }
public:
    //本题分两部分，先找出正解，再搜出所有可能解
    int scoreOfStudents(string _s, vector<int>& answers) {
        s=_s;n=s.size();
        int ans=right_ans();
        vector<int>&possible=dfs(0,n-1);
        bool isPossible[1001]={0};
        for(int a:possible)isPossible[a]=true;
        int score=0;
        //对每个答案先检查是不是正确答案，再看是不是可能答案
        for(int a:answers){
            if(a==ans)score+=5;
            else if(isPossible[a])score+=2;
        }
        return score;
    }
};

int main()
{
    cout<<boolalpha;
    Solution sol;

    string s="7+3*1*2";
    vector<int>answers{20,13,42};
    auto ans=sol.scoreOfStudents(s,answers);
    DBG(ans);

    system("pause");
    return 0;
}